begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"inputmethodhints.h"
end_include
begin_constructor
DECL|function|inputmethodhints
name|inputmethodhints
operator|::
name|inputmethodhints
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QMainWindow
argument_list|(
name|parent
argument_list|)
block|{
name|ui
operator|.
name|setupUi
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|ui
operator|.
name|cbDialableOnly
argument_list|,
name|SIGNAL
argument_list|(
name|stateChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|checkboxChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|ui
operator|.
name|cbDigitsOnly
argument_list|,
name|SIGNAL
argument_list|(
name|stateChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|checkboxChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|ui
operator|.
name|cbEmailOnly
argument_list|,
name|SIGNAL
argument_list|(
name|stateChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|checkboxChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|ui
operator|.
name|cbFormattedNumbersOnly
argument_list|,
name|SIGNAL
argument_list|(
name|stateChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|checkboxChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|ui
operator|.
name|cbHiddenText
argument_list|,
name|SIGNAL
argument_list|(
name|stateChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|checkboxChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|ui
operator|.
name|cbLowercaseOnly
argument_list|,
name|SIGNAL
argument_list|(
name|stateChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|checkboxChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|ui
operator|.
name|cbNoAutoUppercase
argument_list|,
name|SIGNAL
argument_list|(
name|stateChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|checkboxChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|ui
operator|.
name|cbNoPredictiveText
argument_list|,
name|SIGNAL
argument_list|(
name|stateChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|checkboxChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|ui
operator|.
name|cbPreferLowercase
argument_list|,
name|SIGNAL
argument_list|(
name|stateChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|checkboxChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|ui
operator|.
name|cbPreferNumbers
argument_list|,
name|SIGNAL
argument_list|(
name|stateChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|checkboxChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|ui
operator|.
name|cbPreferUpperCase
argument_list|,
name|SIGNAL
argument_list|(
name|stateChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|checkboxChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|ui
operator|.
name|cbUppercaseOnly
argument_list|,
name|SIGNAL
argument_list|(
name|stateChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|checkboxChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|ui
operator|.
name|cbUrlOnly
argument_list|,
name|SIGNAL
argument_list|(
name|stateChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|checkboxChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~inputmethodhints
name|inputmethodhints
operator|::
name|~
name|inputmethodhints
parameter_list|()
block|{  }
end_destructor
begin_function
DECL|function|checkboxChanged
name|void
name|inputmethodhints
operator|::
name|checkboxChanged
parameter_list|(
name|int
parameter_list|)
block|{
name|int
name|flags
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|ui
operator|.
name|cbDialableOnly
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|ImhDialableCharactersOnly
expr_stmt|;
if|if
condition|(
name|ui
operator|.
name|cbDigitsOnly
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|ImhDigitsOnly
expr_stmt|;
if|if
condition|(
name|ui
operator|.
name|cbEmailOnly
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|ImhEmailCharactersOnly
expr_stmt|;
if|if
condition|(
name|ui
operator|.
name|cbFormattedNumbersOnly
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|ImhFormattedNumbersOnly
expr_stmt|;
if|if
condition|(
name|ui
operator|.
name|cbHiddenText
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|ImhHiddenText
expr_stmt|;
if|if
condition|(
name|ui
operator|.
name|cbLowercaseOnly
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|ImhLowercaseOnly
expr_stmt|;
if|if
condition|(
name|ui
operator|.
name|cbNoAutoUppercase
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|ImhNoAutoUppercase
expr_stmt|;
if|if
condition|(
name|ui
operator|.
name|cbNoPredictiveText
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|ImhNoPredictiveText
expr_stmt|;
if|if
condition|(
name|ui
operator|.
name|cbPreferLowercase
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|ImhPreferLowercase
expr_stmt|;
if|if
condition|(
name|ui
operator|.
name|cbPreferNumbers
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|ImhPreferNumbers
expr_stmt|;
if|if
condition|(
name|ui
operator|.
name|cbPreferUpperCase
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|ImhPreferUppercase
expr_stmt|;
if|if
condition|(
name|ui
operator|.
name|cbUppercaseOnly
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|ImhUppercaseOnly
expr_stmt|;
if|if
condition|(
name|ui
operator|.
name|cbUrlOnly
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|ImhUrlCharactersOnly
expr_stmt|;
name|ui
operator|.
name|lineEdit
operator|->
name|clear
argument_list|()
expr_stmt|;
name|ui
operator|.
name|lineEdit
operator|->
name|setInputMethodHints
argument_list|(
name|Qt
operator|::
name|InputMethodHints
argument_list|(
name|flags
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
