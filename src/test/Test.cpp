//
// Created by Gian Cedrick Epilan on 03/07/2020.
//

#include <imgui/imgui.h>
#include "Test.h"

namespace test {

    TestMenu::TestMenu(Test*& currentTestPointer)
        : m_CurrentTests(currentTestPointer)
    {
    }

    void TestMenu::ImGuiRender()
    {
        for (auto& test : m_Tests)
        {
            if(ImGui::Button(test.first.c_str()))
                m_CurrentTests = test.second();
        }
    }

}