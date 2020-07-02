//
// Created by Gian Cedrick Epilan on 02/07/2020.
//

#ifndef LEARN_OPENGL_TEST_H
#define LEARN_OPENGL_TEST_H

namespace test
{
    class Test
    {
    public:
        Test() {}
        virtual ~Test() {}

        virtual void OnUpdate(float deltaTime) {}
        virtual void OnRender() {}
        virtual void ImGuiRender() {}
    private:
    };
}

#endif //LEARN_OPENGL_TEST_H
