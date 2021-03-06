begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"controls.h"
end_include
begin_include
include|#
directive|include
file|<QGridLayout>
end_include
begin_include
include|#
directive|include
file|<QVBoxLayout>
end_include
begin_include
include|#
directive|include
file|<QHBoxLayout>
end_include
begin_include
include|#
directive|include
file|<QRadioButton>
end_include
begin_include
include|#
directive|include
file|<QCheckBox>
end_include
begin_include
include|#
directive|include
file|<QRadioButton>
end_include
begin_include
include|#
directive|include
file|<QButtonGroup>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_constructor
DECL|function|HintControl
name|HintControl
operator|::
name|HintControl
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Hints"
argument_list|)
argument_list|,
name|parent
argument_list|)
member_init_list|,
name|msWindowsFixedSizeDialogCheckBox
argument_list|(
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"MS Windows fixed size dialog"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|x11BypassWindowManagerCheckBox
argument_list|(
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"X11 bypass window manager"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|framelessWindowCheckBox
argument_list|(
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Frameless window"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|windowTitleCheckBox
argument_list|(
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Window title"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|windowSystemMenuCheckBox
argument_list|(
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Window system menu"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|windowMinimizeButtonCheckBox
argument_list|(
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Window minimize button"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|windowMaximizeButtonCheckBox
argument_list|(
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Window maximize button"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|windowFullscreenButtonCheckBox
argument_list|(
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Window fullscreen button"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|windowCloseButtonCheckBox
argument_list|(
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Window close button"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|windowContextHelpButtonCheckBox
argument_list|(
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Window context help button"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|windowShadeButtonCheckBox
argument_list|(
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Window shade button"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|windowStaysOnTopCheckBox
argument_list|(
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Window stays on top"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|windowStaysOnBottomCheckBox
argument_list|(
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Window stays on bottom"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|customizeWindowHintCheckBox
argument_list|(
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Customize window"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|transparentForInputCheckBox
argument_list|(
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Transparent for input"
argument_list|)
argument_list|)
argument_list|)
block|{
name|connect
argument_list|(
name|msWindowsFixedSizeDialogCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|slotCheckBoxChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|x11BypassWindowManagerCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|slotCheckBoxChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|framelessWindowCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|slotCheckBoxChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|windowTitleCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|slotCheckBoxChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|windowSystemMenuCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|slotCheckBoxChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|windowMinimizeButtonCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|slotCheckBoxChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|windowMaximizeButtonCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|slotCheckBoxChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|windowFullscreenButtonCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|slotCheckBoxChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|windowCloseButtonCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|slotCheckBoxChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|windowContextHelpButtonCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|slotCheckBoxChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|windowShadeButtonCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|slotCheckBoxChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|windowStaysOnTopCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|slotCheckBoxChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|windowStaysOnBottomCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|slotCheckBoxChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|customizeWindowHintCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|slotCheckBoxChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|transparentForInputCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|slotCheckBoxChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QGridLayout
modifier|*
name|layout
init|=
operator|new
name|QGridLayout
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|layout
operator|->
name|setSpacing
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|setMargin
argument_list|(
name|ControlLayoutMargin
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|msWindowsFixedSizeDialogCheckBox
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|x11BypassWindowManagerCheckBox
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|framelessWindowCheckBox
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|windowTitleCheckBox
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|windowSystemMenuCheckBox
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|windowMinimizeButtonCheckBox
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|windowMaximizeButtonCheckBox
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|windowFullscreenButtonCheckBox
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|windowCloseButtonCheckBox
argument_list|,
literal|3
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|windowContextHelpButtonCheckBox
argument_list|,
literal|4
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|windowShadeButtonCheckBox
argument_list|,
literal|5
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|windowStaysOnTopCheckBox
argument_list|,
literal|6
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|windowStaysOnBottomCheckBox
argument_list|,
literal|7
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|customizeWindowHintCheckBox
argument_list|,
literal|5
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|transparentForInputCheckBox
argument_list|,
literal|6
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|#
directive|if
name|QT_VERSION
operator|<
literal|0x050000
name|transparentForInputCheckBox
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_constructor
begin_function
DECL|function|hints
name|Qt
operator|::
name|WindowFlags
name|HintControl
operator|::
name|hints
parameter_list|()
specifier|const
block|{
name|Qt
operator|::
name|WindowFlags
name|flags
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|msWindowsFixedSizeDialogCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|MSWindowsFixedSizeDialogHint
expr_stmt|;
if|if
condition|(
name|x11BypassWindowManagerCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|X11BypassWindowManagerHint
expr_stmt|;
if|if
condition|(
name|framelessWindowCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|FramelessWindowHint
expr_stmt|;
if|if
condition|(
name|windowTitleCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|WindowTitleHint
expr_stmt|;
if|if
condition|(
name|windowSystemMenuCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|WindowSystemMenuHint
expr_stmt|;
if|if
condition|(
name|windowMinimizeButtonCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|WindowMinimizeButtonHint
expr_stmt|;
if|if
condition|(
name|windowMaximizeButtonCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|WindowMaximizeButtonHint
expr_stmt|;
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050000
if|if
condition|(
name|windowFullscreenButtonCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|WindowFullscreenButtonHint
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|windowCloseButtonCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|WindowCloseButtonHint
expr_stmt|;
if|if
condition|(
name|windowContextHelpButtonCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|WindowContextHelpButtonHint
expr_stmt|;
if|if
condition|(
name|windowShadeButtonCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|WindowShadeButtonHint
expr_stmt|;
if|if
condition|(
name|windowStaysOnTopCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|WindowStaysOnTopHint
expr_stmt|;
if|if
condition|(
name|windowStaysOnBottomCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|WindowStaysOnBottomHint
expr_stmt|;
if|if
condition|(
name|customizeWindowHintCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|CustomizeWindowHint
expr_stmt|;
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050000
if|if
condition|(
name|transparentForInputCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|WindowTransparentForInput
expr_stmt|;
endif|#
directive|endif
return|return
name|flags
return|;
block|}
end_function
begin_function
DECL|function|setHints
name|void
name|HintControl
operator|::
name|setHints
parameter_list|(
name|Qt
operator|::
name|WindowFlags
name|flags
parameter_list|)
block|{
name|msWindowsFixedSizeDialogCheckBox
operator|->
name|setChecked
argument_list|(
name|flags
operator|&
name|Qt
operator|::
name|MSWindowsFixedSizeDialogHint
argument_list|)
expr_stmt|;
name|x11BypassWindowManagerCheckBox
operator|->
name|setChecked
argument_list|(
name|flags
operator|&
name|Qt
operator|::
name|X11BypassWindowManagerHint
argument_list|)
expr_stmt|;
name|framelessWindowCheckBox
operator|->
name|setChecked
argument_list|(
name|flags
operator|&
name|Qt
operator|::
name|FramelessWindowHint
argument_list|)
expr_stmt|;
name|windowTitleCheckBox
operator|->
name|setChecked
argument_list|(
name|flags
operator|&
name|Qt
operator|::
name|WindowTitleHint
argument_list|)
expr_stmt|;
name|windowSystemMenuCheckBox
operator|->
name|setChecked
argument_list|(
name|flags
operator|&
name|Qt
operator|::
name|WindowSystemMenuHint
argument_list|)
expr_stmt|;
name|windowMinimizeButtonCheckBox
operator|->
name|setChecked
argument_list|(
name|flags
operator|&
name|Qt
operator|::
name|WindowMinimizeButtonHint
argument_list|)
expr_stmt|;
name|windowMaximizeButtonCheckBox
operator|->
name|setChecked
argument_list|(
name|flags
operator|&
name|Qt
operator|::
name|WindowMaximizeButtonHint
argument_list|)
expr_stmt|;
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050000
name|windowFullscreenButtonCheckBox
operator|->
name|setChecked
argument_list|(
name|flags
operator|&
name|Qt
operator|::
name|WindowFullscreenButtonHint
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|windowCloseButtonCheckBox
operator|->
name|setChecked
argument_list|(
name|flags
operator|&
name|Qt
operator|::
name|WindowCloseButtonHint
argument_list|)
expr_stmt|;
name|windowContextHelpButtonCheckBox
operator|->
name|setChecked
argument_list|(
name|flags
operator|&
name|Qt
operator|::
name|WindowContextHelpButtonHint
argument_list|)
expr_stmt|;
name|windowShadeButtonCheckBox
operator|->
name|setChecked
argument_list|(
name|flags
operator|&
name|Qt
operator|::
name|WindowShadeButtonHint
argument_list|)
expr_stmt|;
name|windowStaysOnTopCheckBox
operator|->
name|setChecked
argument_list|(
name|flags
operator|&
name|Qt
operator|::
name|WindowStaysOnTopHint
argument_list|)
expr_stmt|;
name|windowStaysOnBottomCheckBox
operator|->
name|setChecked
argument_list|(
name|flags
operator|&
name|Qt
operator|::
name|WindowStaysOnBottomHint
argument_list|)
expr_stmt|;
name|customizeWindowHintCheckBox
operator|->
name|setChecked
argument_list|(
name|flags
operator|&
name|Qt
operator|::
name|CustomizeWindowHint
argument_list|)
expr_stmt|;
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050000
name|transparentForInputCheckBox
operator|->
name|setChecked
argument_list|(
name|flags
operator|&
name|Qt
operator|::
name|WindowTransparentForInput
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|slotCheckBoxChanged
name|void
name|HintControl
operator|::
name|slotCheckBoxChanged
parameter_list|()
block|{
emit|emit
name|changed
argument_list|(
name|hints
argument_list|()
argument_list|)
emit|;
block|}
end_function
begin_constructor
DECL|function|WindowStateControl
name|WindowStateControl
operator|::
name|WindowStateControl
parameter_list|(
name|unsigned
name|flags
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|group
argument_list|(
operator|new
name|QButtonGroup
argument_list|)
member_init_list|,
name|visibleCheckBox
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|restoreButton
argument_list|(
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"Normal"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|minimizeButton
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|maximizeButton
argument_list|(
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"Maximized"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|fullscreenButton
argument_list|(
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"Fullscreen"
argument_list|)
argument_list|)
argument_list|)
block|{
name|QHBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QHBoxLayout
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|layout
operator|->
name|setSpacing
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|setMargin
argument_list|(
name|ControlLayoutMargin
argument_list|)
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|WantVisibleCheckBox
condition|)
block|{
name|visibleCheckBox
operator|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Visible"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|visibleCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|changed
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|visibleCheckBox
argument_list|)
expr_stmt|;
block|}
name|group
operator|->
name|setExclusive
argument_list|(
literal|true
argument_list|)
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|WantMinimizeRadioButton
condition|)
block|{
name|minimizeButton
operator|=
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"Minimized"
argument_list|)
argument_list|)
expr_stmt|;
name|group
operator|->
name|addButton
argument_list|(
name|minimizeButton
argument_list|,
name|Qt
operator|::
name|WindowMinimized
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|minimizeButton
argument_list|)
expr_stmt|;
block|}
name|group
operator|->
name|addButton
argument_list|(
name|restoreButton
argument_list|,
name|Qt
operator|::
name|WindowNoState
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|restoreButton
argument_list|)
expr_stmt|;
name|group
operator|->
name|addButton
argument_list|(
name|maximizeButton
argument_list|,
name|Qt
operator|::
name|WindowMaximized
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|maximizeButton
argument_list|)
expr_stmt|;
name|group
operator|->
name|addButton
argument_list|(
name|fullscreenButton
argument_list|,
name|Qt
operator|::
name|WindowFullScreen
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|fullscreenButton
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|group
argument_list|,
name|SIGNAL
argument_list|(
name|buttonReleased
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|changed
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|state
name|Qt
operator|::
name|WindowState
name|WindowStateControl
operator|::
name|state
parameter_list|()
specifier|const
block|{
return|return
name|Qt
operator|::
name|WindowState
argument_list|(
name|group
operator|->
name|checkedId
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|setState
name|void
name|WindowStateControl
operator|::
name|setState
parameter_list|(
name|Qt
operator|::
name|WindowState
name|s
parameter_list|)
block|{
name|group
operator|->
name|blockSignals
argument_list|(
literal|true
argument_list|)
expr_stmt|;
if|if
condition|(
name|QAbstractButton
modifier|*
name|b
init|=
name|group
operator|->
name|button
argument_list|(
name|s
argument_list|)
condition|)
name|b
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|group
operator|->
name|blockSignals
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|visibleValue
name|bool
name|WindowStateControl
operator|::
name|visibleValue
parameter_list|()
specifier|const
block|{
return|return
name|visibleCheckBox
operator|&&
name|visibleCheckBox
operator|->
name|isChecked
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setVisibleValue
name|void
name|WindowStateControl
operator|::
name|setVisibleValue
parameter_list|(
name|bool
name|v
parameter_list|)
block|{
if|if
condition|(
name|visibleCheckBox
condition|)
block|{
name|visibleCheckBox
operator|->
name|blockSignals
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|visibleCheckBox
operator|->
name|setChecked
argument_list|(
name|v
argument_list|)
expr_stmt|;
name|visibleCheckBox
operator|->
name|blockSignals
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_constructor
DECL|function|WindowStatesControl
name|WindowStatesControl
operator|::
name|WindowStatesControl
parameter_list|(
name|unsigned
name|flags
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"States"
argument_list|)
argument_list|,
name|parent
argument_list|)
member_init_list|,
name|visibleCheckBox
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|activeCheckBox
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|minimizeCheckBox
argument_list|(
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Minimized"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|stateControl
argument_list|(
operator|new
name|WindowStateControl
argument_list|(
literal|0
argument_list|)
argument_list|)
block|{
name|QHBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QHBoxLayout
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|layout
operator|->
name|setSpacing
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|setMargin
argument_list|(
name|ControlLayoutMargin
argument_list|)
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|WantVisibleCheckBox
condition|)
block|{
name|visibleCheckBox
operator|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Visible"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|visibleCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|changed
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|visibleCheckBox
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|flags
operator|&
name|WantActiveCheckBox
condition|)
block|{
name|activeCheckBox
operator|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Active"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|activeCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|changed
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|activeCheckBox
argument_list|)
expr_stmt|;
block|}
name|layout
operator|->
name|addWidget
argument_list|(
name|minimizeCheckBox
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|stateControl
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|stateControl
argument_list|,
name|SIGNAL
argument_list|(
name|changed
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|changed
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|minimizeCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|changed
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|states
name|Qt
operator|::
name|WindowStates
name|WindowStatesControl
operator|::
name|states
parameter_list|()
specifier|const
block|{
name|Qt
operator|::
name|WindowStates
name|s
init|=
name|stateControl
operator|->
name|state
argument_list|()
decl_stmt|;
if|if
condition|(
name|minimizeCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
name|s
operator||=
name|Qt
operator|::
name|WindowMinimized
expr_stmt|;
if|if
condition|(
name|activeValue
argument_list|()
condition|)
name|s
operator||=
name|Qt
operator|::
name|WindowActive
expr_stmt|;
return|return
name|s
return|;
block|}
end_function
begin_function
DECL|function|setStates
name|void
name|WindowStatesControl
operator|::
name|setStates
parameter_list|(
name|Qt
operator|::
name|WindowStates
name|s
parameter_list|)
block|{
name|minimizeCheckBox
operator|->
name|blockSignals
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|minimizeCheckBox
operator|->
name|setChecked
argument_list|(
name|s
operator|&
name|Qt
operator|::
name|WindowMinimized
argument_list|)
expr_stmt|;
name|minimizeCheckBox
operator|->
name|blockSignals
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|s
operator|&=
operator|~
name|Qt
operator|::
name|WindowMinimized
expr_stmt|;
name|stateControl
operator|->
name|setState
argument_list|(
name|Qt
operator|::
name|WindowState
argument_list|(
name|int
argument_list|(
name|s
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|setActiveValue
argument_list|(
name|s
operator|&
name|Qt
operator|::
name|WindowActive
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|visibleValue
name|bool
name|WindowStatesControl
operator|::
name|visibleValue
parameter_list|()
specifier|const
block|{
return|return
name|visibleCheckBox
operator|&&
name|visibleCheckBox
operator|->
name|isChecked
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setVisibleValue
name|void
name|WindowStatesControl
operator|::
name|setVisibleValue
parameter_list|(
name|bool
name|v
parameter_list|)
block|{
if|if
condition|(
name|visibleCheckBox
condition|)
block|{
name|visibleCheckBox
operator|->
name|blockSignals
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|visibleCheckBox
operator|->
name|setChecked
argument_list|(
name|v
argument_list|)
expr_stmt|;
name|visibleCheckBox
operator|->
name|blockSignals
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|activeValue
name|bool
name|WindowStatesControl
operator|::
name|activeValue
parameter_list|()
specifier|const
block|{
return|return
name|activeCheckBox
operator|&&
name|activeCheckBox
operator|->
name|isChecked
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setActiveValue
name|void
name|WindowStatesControl
operator|::
name|setActiveValue
parameter_list|(
name|bool
name|v
parameter_list|)
block|{
if|if
condition|(
name|activeCheckBox
condition|)
block|{
name|activeCheckBox
operator|->
name|blockSignals
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|activeCheckBox
operator|->
name|setChecked
argument_list|(
name|v
argument_list|)
expr_stmt|;
name|activeCheckBox
operator|->
name|blockSignals
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_constructor
DECL|function|TypeControl
name|TypeControl
operator|::
name|TypeControl
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Type"
argument_list|)
argument_list|,
name|parent
argument_list|)
member_init_list|,
name|group
argument_list|(
operator|new
name|QButtonGroup
argument_list|)
member_init_list|,
name|windowRadioButton
argument_list|(
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"Window"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|dialogRadioButton
argument_list|(
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"Dialog"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|sheetRadioButton
argument_list|(
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"Sheet"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|drawerRadioButton
argument_list|(
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"Drawer"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|popupRadioButton
argument_list|(
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"Popup"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|toolRadioButton
argument_list|(
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"Tool"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|toolTipRadioButton
argument_list|(
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"Tooltip"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|splashScreenRadioButton
argument_list|(
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"Splash screen"
argument_list|)
argument_list|)
argument_list|)
block|{
name|group
operator|->
name|setExclusive
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QGridLayout
modifier|*
name|layout
init|=
operator|new
name|QGridLayout
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|layout
operator|->
name|setSpacing
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|setMargin
argument_list|(
name|ControlLayoutMargin
argument_list|)
expr_stmt|;
name|group
operator|->
name|addButton
argument_list|(
name|windowRadioButton
argument_list|,
name|Qt
operator|::
name|Window
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|windowRadioButton
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|group
operator|->
name|addButton
argument_list|(
name|dialogRadioButton
argument_list|,
name|Qt
operator|::
name|Dialog
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|dialogRadioButton
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|group
operator|->
name|addButton
argument_list|(
name|sheetRadioButton
argument_list|,
name|Qt
operator|::
name|Sheet
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|sheetRadioButton
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|group
operator|->
name|addButton
argument_list|(
name|drawerRadioButton
argument_list|,
name|Qt
operator|::
name|Drawer
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|drawerRadioButton
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|group
operator|->
name|addButton
argument_list|(
name|popupRadioButton
argument_list|,
name|Qt
operator|::
name|Popup
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|popupRadioButton
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|group
operator|->
name|addButton
argument_list|(
name|toolRadioButton
argument_list|,
name|Qt
operator|::
name|Tool
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|toolRadioButton
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|group
operator|->
name|addButton
argument_list|(
name|toolTipRadioButton
argument_list|,
name|Qt
operator|::
name|ToolTip
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|toolTipRadioButton
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|group
operator|->
name|addButton
argument_list|(
name|splashScreenRadioButton
argument_list|,
name|Qt
operator|::
name|SplashScreen
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|splashScreenRadioButton
argument_list|,
literal|3
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|group
argument_list|,
name|SIGNAL
argument_list|(
name|buttonReleased
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|slotChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|type
name|Qt
operator|::
name|WindowFlags
name|TypeControl
operator|::
name|type
parameter_list|()
specifier|const
block|{
return|return
name|Qt
operator|::
name|WindowFlags
argument_list|(
name|group
operator|->
name|checkedId
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|setType
name|void
name|TypeControl
operator|::
name|setType
parameter_list|(
name|Qt
operator|::
name|WindowFlags
name|s
parameter_list|)
block|{
if|if
condition|(
name|QAbstractButton
modifier|*
name|b
init|=
name|group
operator|->
name|button
argument_list|(
name|s
operator|&
name|Qt
operator|::
name|WindowType_Mask
argument_list|)
condition|)
name|b
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|slotChanged
name|void
name|TypeControl
operator|::
name|slotChanged
parameter_list|()
block|{
emit|emit
name|changed
argument_list|(
name|type
argument_list|()
argument_list|)
emit|;
block|}
end_function
end_unit
