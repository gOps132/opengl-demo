//
// Created by Gian Cedrick Epilan on 02/07/2020.
//

#ifndef LEARN_OPENGL_TEST_H
#define LEARN_OPENGL_TEST_H

#include <iostream>
#include <vector>
#include <functional>

namespace test {

    class Test
    {
    public:
        Test() {}
        virtual ~Test() {}

        virtual void OnUpdate(float deltaTime) {}
        virtual void OnRender() {}
        virtual void ImGuiRender() {}
    };

    class TestMenu : public Test
    {
    public:
        TestMenu(Test*& currentTestPointer);

        void ImGuiRender() override;

        template<typename T>
        void RegisterTest(const std::string& name)
        {
            std::cout << "Registering Test" << name << std::endl;

            m_Tests.push_back(std::make_pair(name, [](){ return new T(); }));
        }

    private:
        Test*& m_CurrentTests;
        std::vector<std::pair<std::string, std::function<Test*()>>> m_Tests;
    };

}

#endif //LEARN_OPENGL_TEST_H
