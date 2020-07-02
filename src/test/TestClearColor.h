//
// Created by Gian Cedrick Epilan on 02/07/2020.
//

#ifndef LEARN_OPENGL_TESTCLEARCOLOR_H
#define LEARN_OPENGL_TESTCLEARCOLOR_H

#include "Test.h"

namespace test
{
    class TestClearColor : public Test
    {
    public:
        TestClearColor();
        ~TestClearColor();

        void OnUpdate(float deltaTime) override;
        void OnRender() override;
        void ImGuiRender() override;

    private:
        float m_ClearColor[4];

    };
}

#endif //LEARN_OPENGL_TESTCLEARCOLOR_H
