begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|"qcheckbox.h"
end_include
begin_include
include|#
directive|include
file|<qapplication.h>
end_include
begin_include
include|#
directive|include
file|<qpixmap.h>
end_include
begin_include
include|#
directive|include
file|<qdatetime.h>
end_include
begin_include
include|#
directive|include
file|<qcheckbox.h>
end_include
begin_comment
comment|//TESTED_CLASS=
end_comment
begin_comment
comment|//TESTED_FILES=
end_comment
begin_class
DECL|class|tst_QCheckBox
class|class
name|tst_QCheckBox
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QCheckBox
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QCheckBox
parameter_list|()
destructor_decl|;
public|public
name|slots
public|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|cleanupTestCase
parameter_list|()
function_decl|;
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
private|private
name|slots
private|:
name|void
name|isChecked
parameter_list|()
function_decl|;
name|void
name|setChecked
parameter_list|()
function_decl|;
name|void
name|setNoChange
parameter_list|()
function_decl|;
name|void
name|setTriState
parameter_list|()
function_decl|;
name|void
name|isTriState
parameter_list|()
function_decl|;
name|void
name|text
parameter_list|()
function_decl|;
name|void
name|setText_data
parameter_list|()
function_decl|;
name|void
name|setText
parameter_list|()
function_decl|;
name|void
name|isToggleButton
parameter_list|()
function_decl|;
name|void
name|setDown
parameter_list|()
function_decl|;
name|void
name|isDown
parameter_list|()
function_decl|;
name|void
name|isOn
parameter_list|()
function_decl|;
name|void
name|checkState
parameter_list|()
function_decl|;
name|void
name|autoRepeat
parameter_list|()
function_decl|;
name|void
name|setAutoRepeat
parameter_list|()
function_decl|;
name|void
name|toggle
parameter_list|()
function_decl|;
name|void
name|pressed
parameter_list|()
function_decl|;
name|void
name|released
parameter_list|()
function_decl|;
name|void
name|clicked
parameter_list|()
function_decl|;
name|void
name|toggled
parameter_list|()
function_decl|;
name|void
name|stateChanged
parameter_list|()
function_decl|;
name|void
name|foregroundRole
parameter_list|()
function_decl|;
name|void
name|minimumSizeHint
parameter_list|()
function_decl|;
protected|protected
name|slots
protected|:
name|void
name|onClicked
parameter_list|()
function_decl|;
name|void
name|onToggled
parameter_list|(
name|bool
name|on
parameter_list|)
function_decl|;
name|void
name|onPressed
parameter_list|()
function_decl|;
name|void
name|onReleased
parameter_list|()
function_decl|;
name|void
name|onStateChanged
parameter_list|(
name|int
name|state
parameter_list|)
function_decl|;
private|private:
DECL|member|click_count
name|uint
name|click_count
decl_stmt|;
DECL|member|toggle_count
name|uint
name|toggle_count
decl_stmt|;
DECL|member|press_count
name|uint
name|press_count
decl_stmt|;
DECL|member|release_count
name|uint
name|release_count
decl_stmt|;
DECL|member|cur_state
name|int
name|cur_state
decl_stmt|;
DECL|member|tmp
name|uint
name|tmp
decl_stmt|;
DECL|member|testWidget
name|QCheckBox
modifier|*
name|testWidget
decl_stmt|;
DECL|member|tmp2
name|uint
name|tmp2
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QCheckBox
name|tst_QCheckBox
operator|::
name|tst_QCheckBox
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QCheckBox
name|tst_QCheckBox
operator|::
name|~
name|tst_QCheckBox
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|initTestCase
name|void
name|tst_QCheckBox
operator|::
name|initTestCase
parameter_list|()
block|{
comment|// Create the test class
name|testWidget
operator|=
operator|new
name|QCheckBox
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|testWidget
operator|->
name|setObjectName
argument_list|(
literal|"testObject"
argument_list|)
expr_stmt|;
name|testWidget
operator|->
name|resize
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|testWidget
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|tst_QCheckBox
operator|::
name|cleanupTestCase
parameter_list|()
block|{
operator|delete
name|testWidget
expr_stmt|;
name|testWidget
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|init
name|void
name|tst_QCheckBox
operator|::
name|init
parameter_list|()
block|{
name|testWidget
operator|->
name|setTristate
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
name|testWidget
operator|->
name|setChecked
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
name|testWidget
operator|->
name|setAutoRepeat
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QCheckBox
operator|::
name|cleanup
parameter_list|()
block|{
name|disconnect
argument_list|(
name|testWidget
argument_list|,
name|SIGNAL
argument_list|(
name|pressed
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|onPressed
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|disconnect
argument_list|(
name|testWidget
argument_list|,
name|SIGNAL
argument_list|(
name|released
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|onReleased
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|disconnect
argument_list|(
name|testWidget
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
name|onClicked
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|disconnect
argument_list|(
name|testWidget
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
name|SLOT
argument_list|(
name|onToggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|onClicked
name|void
name|tst_QCheckBox
operator|::
name|onClicked
parameter_list|()
block|{
name|click_count
operator|++
expr_stmt|;
block|}
end_function
begin_function
DECL|function|onPressed
name|void
name|tst_QCheckBox
operator|::
name|onPressed
parameter_list|()
block|{
name|press_count
operator|++
expr_stmt|;
block|}
end_function
begin_function
DECL|function|onReleased
name|void
name|tst_QCheckBox
operator|::
name|onReleased
parameter_list|()
block|{
name|release_count
operator|++
expr_stmt|;
block|}
end_function
begin_function
DECL|function|onToggled
name|void
name|tst_QCheckBox
operator|::
name|onToggled
parameter_list|(
name|bool
comment|/*on*/
parameter_list|)
block|{
name|toggle_count
operator|++
expr_stmt|;
block|}
end_function
begin_comment
comment|// ***************************************************
end_comment
begin_function
DECL|function|isChecked
name|void
name|tst_QCheckBox
operator|::
name|isChecked
parameter_list|()
block|{
name|DEPENDS_ON
argument_list|(
literal|"setChecked"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setChecked
name|void
name|tst_QCheckBox
operator|::
name|setChecked
parameter_list|()
block|{
name|testWidget
operator|->
name|setChecked
argument_list|(
name|TRUE
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|testWidget
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|testWidget
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|testWidget
operator|->
name|checkState
argument_list|()
operator|==
name|Qt
operator|::
name|Checked
argument_list|)
expr_stmt|;
name|testWidget
operator|->
name|setChecked
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|testWidget
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|testWidget
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|testWidget
operator|->
name|checkState
argument_list|()
operator|==
name|Qt
operator|::
name|Unchecked
argument_list|)
expr_stmt|;
name|testWidget
operator|->
name|setChecked
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|keyClick
argument_list|(
name|testWidget
argument_list|,
literal|' '
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|testWidget
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|keyClick
argument_list|(
name|testWidget
argument_list|,
literal|' '
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|testWidget
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setTriState
name|void
name|tst_QCheckBox
operator|::
name|setTriState
parameter_list|()
block|{
name|testWidget
operator|->
name|setTristate
argument_list|(
name|TRUE
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|testWidget
operator|->
name|isTristate
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|testWidget
operator|->
name|checkState
argument_list|()
operator|==
name|Qt
operator|::
name|Unchecked
argument_list|)
expr_stmt|;
name|testWidget
operator|->
name|setCheckState
argument_list|(
name|Qt
operator|::
name|PartiallyChecked
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|testWidget
operator|->
name|checkState
argument_list|()
operator|==
name|Qt
operator|::
name|PartiallyChecked
argument_list|)
expr_stmt|;
name|testWidget
operator|->
name|setChecked
argument_list|(
name|TRUE
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|testWidget
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|testWidget
operator|->
name|checkState
argument_list|()
operator|==
name|Qt
operator|::
name|Checked
argument_list|)
expr_stmt|;
name|testWidget
operator|->
name|setChecked
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|testWidget
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|testWidget
operator|->
name|checkState
argument_list|()
operator|==
name|Qt
operator|::
name|Unchecked
argument_list|)
expr_stmt|;
name|testWidget
operator|->
name|setCheckState
argument_list|(
name|Qt
operator|::
name|PartiallyChecked
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|testWidget
operator|->
name|checkState
argument_list|()
operator|==
name|Qt
operator|::
name|PartiallyChecked
argument_list|)
expr_stmt|;
name|testWidget
operator|->
name|setTristate
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|testWidget
operator|->
name|isTristate
argument_list|()
argument_list|)
expr_stmt|;
name|testWidget
operator|->
name|setCheckState
argument_list|(
name|Qt
operator|::
name|PartiallyChecked
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|testWidget
operator|->
name|checkState
argument_list|()
operator|==
name|Qt
operator|::
name|PartiallyChecked
argument_list|)
expr_stmt|;
name|testWidget
operator|->
name|setChecked
argument_list|(
name|TRUE
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|testWidget
operator|->
name|checkState
argument_list|()
operator|==
name|Qt
operator|::
name|Checked
argument_list|)
expr_stmt|;
name|testWidget
operator|->
name|setChecked
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|testWidget
operator|->
name|checkState
argument_list|()
operator|==
name|Qt
operator|::
name|Unchecked
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isTriState
name|void
name|tst_QCheckBox
operator|::
name|isTriState
parameter_list|()
block|{
name|DEPENDS_ON
argument_list|(
literal|"setTriState"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setNoChange
name|void
name|tst_QCheckBox
operator|::
name|setNoChange
parameter_list|()
block|{
name|DEPENDS_ON
argument_list|(
literal|"setTriState"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|text
name|void
name|tst_QCheckBox
operator|::
name|text
parameter_list|()
block|{
name|DEPENDS_ON
argument_list|(
literal|"setText"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setText_data
name|void
name|tst_QCheckBox
operator|::
name|setText_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"s1"
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WIN32
name|QTest
operator|::
name|newRow
argument_list|(
literal|"win32_data0"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"This is a text"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"win32_data1"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"A"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"win32_data2"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"ABCDEFG "
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"win32_data3"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"Text\nwith a cr-lf"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"win32_data4"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|""
argument_list|)
expr_stmt|;
else|#
directive|else
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data0"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"This is a text"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data1"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"A"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data2"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"ABCDEFG "
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data3"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"Text\nwith a cr-lf"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data4"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|""
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|setText
name|void
name|tst_QCheckBox
operator|::
name|setText
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|s1
argument_list|)
expr_stmt|;
name|testWidget
operator|->
name|setText
argument_list|(
name|s1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|testWidget
operator|->
name|text
argument_list|()
argument_list|,
name|s1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setDown
name|void
name|tst_QCheckBox
operator|::
name|setDown
parameter_list|()
block|{
name|testWidget
operator|->
name|setDown
argument_list|(
name|TRUE
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|testWidget
operator|->
name|isDown
argument_list|()
argument_list|)
expr_stmt|;
name|testWidget
operator|->
name|setDown
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|testWidget
operator|->
name|isDown
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isDown
name|void
name|tst_QCheckBox
operator|::
name|isDown
parameter_list|()
block|{
name|DEPENDS_ON
argument_list|(
literal|"setDown"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isOn
name|void
name|tst_QCheckBox
operator|::
name|isOn
parameter_list|()
block|{
name|DEPENDS_ON
argument_list|(
literal|"setChecked"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|checkState
name|void
name|tst_QCheckBox
operator|::
name|checkState
parameter_list|()
block|{
name|DEPENDS_ON
argument_list|(
literal|"setChecked"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|autoRepeat
name|void
name|tst_QCheckBox
operator|::
name|autoRepeat
parameter_list|()
block|{
name|DEPENDS_ON
argument_list|(
literal|"setAutoRepeat"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setAutoRepeat
name|void
name|tst_QCheckBox
operator|::
name|setAutoRepeat
parameter_list|()
block|{
comment|// setAutoRepeat has no effect on toggle buttons
name|QVERIFY
argument_list|(
name|testWidget
operator|->
name|isCheckable
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|toggle
name|void
name|tst_QCheckBox
operator|::
name|toggle
parameter_list|()
block|{
name|bool
name|cur_state
decl_stmt|;
name|cur_state
operator|=
name|testWidget
operator|->
name|isChecked
argument_list|()
expr_stmt|;
name|testWidget
operator|->
name|toggle
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|cur_state
operator|!=
name|testWidget
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|cur_state
operator|=
name|testWidget
operator|->
name|isChecked
argument_list|()
expr_stmt|;
name|testWidget
operator|->
name|toggle
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|cur_state
operator|!=
name|testWidget
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|cur_state
operator|=
name|testWidget
operator|->
name|isChecked
argument_list|()
expr_stmt|;
name|testWidget
operator|->
name|toggle
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|cur_state
operator|!=
name|testWidget
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|pressed
name|void
name|tst_QCheckBox
operator|::
name|pressed
parameter_list|()
block|{
name|connect
argument_list|(
name|testWidget
argument_list|,
name|SIGNAL
argument_list|(
name|pressed
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|onPressed
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|testWidget
argument_list|,
name|SIGNAL
argument_list|(
name|released
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|onReleased
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|press_count
operator|=
literal|0
expr_stmt|;
name|release_count
operator|=
literal|0
expr_stmt|;
name|testWidget
operator|->
name|setDown
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|testWidget
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|keyPress
argument_list|(
name|testWidget
argument_list|,
name|Qt
operator|::
name|Key_Space
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|100
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|press_count
operator|==
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|release_count
operator|==
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|testWidget
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|keyRelease
argument_list|(
name|testWidget
argument_list|,
name|Qt
operator|::
name|Key_Space
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|100
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|press_count
operator|==
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|release_count
operator|==
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|testWidget
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|released
name|void
name|tst_QCheckBox
operator|::
name|released
parameter_list|()
block|{
name|DEPENDS_ON
argument_list|(
literal|"pressed"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|clicked
name|void
name|tst_QCheckBox
operator|::
name|clicked
parameter_list|()
block|{
name|DEPENDS_ON
argument_list|(
literal|"pressed"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|toggled
name|void
name|tst_QCheckBox
operator|::
name|toggled
parameter_list|()
block|{
name|connect
argument_list|(
name|testWidget
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
name|SLOT
argument_list|(
name|onToggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|click_count
operator|=
literal|0
expr_stmt|;
name|toggle_count
operator|=
literal|0
expr_stmt|;
name|testWidget
operator|->
name|toggle
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|toggle_count
argument_list|,
operator|(
name|uint
operator|)
literal|1
argument_list|)
expr_stmt|;
name|testWidget
operator|->
name|toggle
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|toggle_count
argument_list|,
operator|(
name|uint
operator|)
literal|2
argument_list|)
expr_stmt|;
name|testWidget
operator|->
name|toggle
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|toggle_count
argument_list|,
operator|(
name|uint
operator|)
literal|3
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|click_count
argument_list|,
operator|(
name|uint
operator|)
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|onStateChanged
name|void
name|tst_QCheckBox
operator|::
name|onStateChanged
parameter_list|(
name|int
name|state
parameter_list|)
block|{
name|cur_state
operator|=
name|state
expr_stmt|;
block|}
end_function
begin_function
DECL|function|stateChanged
name|void
name|tst_QCheckBox
operator|::
name|stateChanged
parameter_list|()
block|{
name|QSignalSpy
name|stateChangedSpy
argument_list|(
name|testWidget
argument_list|,
name|SIGNAL
argument_list|(
name|stateChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|testWidget
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
name|onStateChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|cur_state
operator|=
operator|-
literal|1
expr_stmt|;
name|testWidget
operator|->
name|setChecked
argument_list|(
name|TRUE
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|cur_state
argument_list|,
operator|(
name|int
operator|)
literal|2
argument_list|)
expr_stmt|;
name|cur_state
operator|=
operator|-
literal|1
expr_stmt|;
name|testWidget
operator|->
name|setChecked
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|cur_state
argument_list|,
operator|(
name|int
operator|)
literal|0
argument_list|)
expr_stmt|;
name|cur_state
operator|=
operator|-
literal|1
expr_stmt|;
name|testWidget
operator|->
name|setCheckState
argument_list|(
name|Qt
operator|::
name|PartiallyChecked
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|cur_state
argument_list|,
operator|(
name|int
operator|)
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|stateChangedSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|testWidget
operator|->
name|setCheckState
argument_list|(
name|Qt
operator|::
name|PartiallyChecked
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|stateChangedSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isToggleButton
name|void
name|tst_QCheckBox
operator|::
name|isToggleButton
parameter_list|()
block|{
name|QVERIFY
argument_list|(
name|testWidget
operator|->
name|isCheckable
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|foregroundRole
name|void
name|tst_QCheckBox
operator|::
name|foregroundRole
parameter_list|()
block|{
name|QVERIFY
argument_list|(
name|testWidget
operator|->
name|foregroundRole
argument_list|()
operator|==
name|QPalette
operator|::
name|WindowText
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|minimumSizeHint
name|void
name|tst_QCheckBox
operator|::
name|minimumSizeHint
parameter_list|()
block|{
name|QCheckBox
name|box
argument_list|(
name|tr
argument_list|(
literal|"CheckBox's sizeHint is the same as it's minimumSizeHint"
argument_list|)
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|box
operator|.
name|sizeHint
argument_list|()
argument_list|,
name|box
operator|.
name|minimumSizeHint
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QCheckBox
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qcheckbox.moc"
end_include
end_unit
