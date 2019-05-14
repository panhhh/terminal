// Copyright (c) Microsoft Corporation.
// Licensed under the MIT license.

#pragma once
#include <winrt/Microsoft.UI.Xaml.Controls.h>
#include "Pane.h"

class Tab
{

public:
    Tab(GUID profile, winrt::Microsoft::Terminal::TerminalControl::TermControl control);
    ~Tab();

    winrt::Microsoft::UI::Xaml::Controls::TabViewItem GetTabViewItem();
    winrt::Windows::UI::Xaml::UIElement GetRootElement();
    winrt::Microsoft::Terminal::TerminalControl::TermControl GetFocusedTerminalControl();
    std::optional<GUID> GetLastFocusedProfile() const noexcept;

    bool IsFocused();
    void SetFocused(bool focused);

    void Scroll(int delta);
    void SplitVertical(GUID profile, winrt::Microsoft::Terminal::TerminalControl::TermControl control);
    void SplitHorizontal(GUID profile, winrt::Microsoft::Terminal::TerminalControl::TermControl control);

    void CheckFocus();

    void CheckUpdateSettings(winrt::Microsoft::Terminal::Settings::TerminalSettings settings, GUID profile);
    winrt::hstring CheckTitleUpdate();
    void SetTabText(const winrt::hstring& text);

private:

    std::shared_ptr<Pane> _rootPane;

    bool _focused;
    winrt::Microsoft::UI::Xaml::Controls::TabViewItem _tabViewItem;

    void _MakeTabViewItem();
    void _Focus();
};
