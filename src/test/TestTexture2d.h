//
// Created by Gian Cedrick Epilan on 02/07/2020.
//

#ifndef LEARN_OPENGL_TESTTEXTURE2D_H
#define LEARN_OPENGL_TESTTEXTURE2D_H

#include "Test.h"

namespace test {

    class TestTexture2d : public Test
    {
    public:
        TestTexture2d();
        ~TestTexture2d();

        void OnUpdate(float deltaTime) override;
        void OnRender() override;
        void ImGuiRender() override;

    private:

    };
}

#endif //LEARN_OPENGL_TESTCLEARCOLOR_H
