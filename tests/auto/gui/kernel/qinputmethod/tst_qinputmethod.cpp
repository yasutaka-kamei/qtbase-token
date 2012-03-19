begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qinputmethod_p.h>
end_include
begin_include
include|#
directive|include
file|<qplatforminputcontext_qpa.h>
end_include
begin_include
include|#
directive|include
file|"../../../shared/platforminputcontext.h"
end_include
begin_class
DECL|class|InputItem
class|class
name|InputItem
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|InputItem
name|InputItem
parameter_list|()
member_init_list|:
name|cursorRectangle
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
member_init_list|,
name|m_enabled
argument_list|(
literal|true
argument_list|)
block|{}
DECL|function|event
name|bool
name|event
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|InputMethodQuery
condition|)
block|{
name|QInputMethodQueryEvent
modifier|*
name|query
init|=
cast|static_cast
argument_list|<
name|QInputMethodQueryEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
if|if
condition|(
name|query
operator|->
name|queries
argument_list|()
operator|&
name|Qt
operator|::
name|ImEnabled
condition|)
name|query
operator|->
name|setValue
argument_list|(
name|Qt
operator|::
name|ImEnabled
argument_list|,
name|m_enabled
argument_list|)
expr_stmt|;
if|if
condition|(
name|query
operator|->
name|queries
argument_list|()
operator|&
name|Qt
operator|::
name|ImCursorRectangle
condition|)
name|query
operator|->
name|setValue
argument_list|(
name|Qt
operator|::
name|ImCursorRectangle
argument_list|,
name|cursorRectangle
argument_list|)
expr_stmt|;
if|if
condition|(
name|query
operator|->
name|queries
argument_list|()
operator|&
name|Qt
operator|::
name|ImPreferredLanguage
condition|)
name|query
operator|->
name|setValue
argument_list|(
name|Qt
operator|::
name|ImPreferredLanguage
argument_list|,
name|QString
argument_list|(
literal|"English"
argument_list|)
argument_list|)
expr_stmt|;
name|m_lastQueries
operator|=
name|query
operator|->
name|queries
argument_list|()
expr_stmt|;
name|query
operator|->
name|accept
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
DECL|function|setEnabled
name|void
name|setEnabled
parameter_list|(
name|bool
name|enabled
parameter_list|)
block|{
if|if
condition|(
name|enabled
operator|!=
name|m_enabled
condition|)
block|{
name|m_enabled
operator|=
name|enabled
expr_stmt|;
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|update
argument_list|(
name|Qt
operator|::
name|ImEnabled
argument_list|)
expr_stmt|;
block|}
block|}
DECL|member|cursorRectangle
name|QRectF
name|cursorRectangle
decl_stmt|;
DECL|member|m_lastQueries
name|Qt
operator|::
name|InputMethodQueries
name|m_lastQueries
decl_stmt|;
DECL|member|m_enabled
name|bool
name|m_enabled
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|DummyWindow
class|class
name|DummyWindow
super|:
specifier|public
name|QWindow
block|{
public|public:
DECL|function|DummyWindow
name|DummyWindow
parameter_list|()
member_init_list|:
name|m_focusObject
argument_list|(
literal|0
argument_list|)
block|{}
DECL|function|focusObject
specifier|virtual
name|QObject
modifier|*
name|focusObject
parameter_list|()
specifier|const
block|{
return|return
name|m_focusObject
return|;
block|}
DECL|function|setFocusObject
name|void
name|setFocusObject
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|)
block|{
name|m_focusObject
operator|=
name|object
expr_stmt|;
emit|emit
name|focusObjectChanged
argument_list|(
name|object
argument_list|)
emit|;
block|}
DECL|member|m_focusObject
name|QObject
modifier|*
name|m_focusObject
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|tst_qinputmethod
class|class
name|tst_qinputmethod
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|tst_qinputmethod
name|tst_qinputmethod
parameter_list|()
block|{}
DECL|function|~tst_qinputmethod
specifier|virtual
name|~
name|tst_qinputmethod
parameter_list|()
block|{}
private|private
name|slots
private|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|isVisible
parameter_list|()
function_decl|;
name|void
name|animating
parameter_list|()
function_decl|;
name|void
name|keyboarRectangle
parameter_list|()
function_decl|;
name|void
name|inputItem
parameter_list|()
function_decl|;
name|void
name|inputItemTransform
parameter_list|()
function_decl|;
name|void
name|cursorRectangle
parameter_list|()
function_decl|;
name|void
name|invokeAction
parameter_list|()
function_decl|;
name|void
name|reset
parameter_list|()
function_decl|;
name|void
name|commit
parameter_list|()
function_decl|;
name|void
name|update
parameter_list|()
function_decl|;
name|void
name|query
parameter_list|()
function_decl|;
name|void
name|inputDirection
parameter_list|()
function_decl|;
private|private:
DECL|member|m_inputItem
name|InputItem
name|m_inputItem
decl_stmt|;
DECL|member|m_platformInputContext
name|PlatformInputContext
name|m_platformInputContext
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|initTestCase
name|void
name|tst_qinputmethod
operator|::
name|initTestCase
parameter_list|()
block|{
name|QInputMethodPrivate
modifier|*
name|inputMethodPrivate
init|=
name|QInputMethodPrivate
operator|::
name|get
argument_list|(
name|qApp
operator|->
name|inputMethod
argument_list|()
argument_list|)
decl_stmt|;
name|inputMethodPrivate
operator|->
name|testContext
operator|=
operator|&
name|m_platformInputContext
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isVisible
name|void
name|tst_qinputmethod
operator|::
name|isVisible
parameter_list|()
block|{
name|QCOMPARE
argument_list|(
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|isVisible
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|show
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|isVisible
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|hide
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|isVisible
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|setVisible
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|isVisible
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|setVisible
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|isVisible
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|animating
name|void
name|tst_qinputmethod
operator|::
name|animating
parameter_list|()
block|{
name|QCOMPARE
argument_list|(
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|isAnimating
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|m_platformInputContext
operator|.
name|m_animating
operator|=
literal|true
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|isAnimating
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|m_platformInputContext
operator|.
name|m_animating
operator|=
literal|false
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|isAnimating
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QSignalSpy
name|spy
argument_list|(
name|qApp
operator|->
name|inputMethod
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|animatingChanged
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|m_platformInputContext
operator|.
name|emitAnimatingChanged
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|keyboarRectangle
name|void
name|tst_qinputmethod
operator|::
name|keyboarRectangle
parameter_list|()
block|{
name|QCOMPARE
argument_list|(
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|keyboardRectangle
argument_list|()
argument_list|,
name|QRectF
argument_list|()
argument_list|)
expr_stmt|;
name|m_platformInputContext
operator|.
name|m_keyboardRect
operator|=
name|QRectF
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|keyboardRectangle
argument_list|()
argument_list|,
name|QRectF
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
argument_list|)
expr_stmt|;
name|QSignalSpy
name|spy
argument_list|(
name|qApp
operator|->
name|inputMethod
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|keyboardRectangleChanged
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|m_platformInputContext
operator|.
name|emitKeyboardRectChanged
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|inputItem
name|void
name|tst_qinputmethod
operator|::
name|inputItem
parameter_list|()
block|{
name|QVERIFY
argument_list|(
operator|!
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|inputItem
argument_list|()
argument_list|)
expr_stmt|;
name|QSignalSpy
name|spy
argument_list|(
name|qApp
operator|->
name|inputMethod
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|inputItemChanged
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|setInputItem
argument_list|(
operator|&
name|m_inputItem
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|inputItem
argument_list|()
argument_list|,
operator|&
name|m_inputItem
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// reset
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|setInputItem
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|inputItemTransform
name|void
name|tst_qinputmethod
operator|::
name|inputItemTransform
parameter_list|()
block|{
name|QCOMPARE
argument_list|(
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|inputItemTransform
argument_list|()
argument_list|,
name|QTransform
argument_list|()
argument_list|)
expr_stmt|;
name|QSignalSpy
name|spy
argument_list|(
name|qApp
operator|->
name|inputMethod
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|cursorRectangleChanged
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QTransform
name|transform
decl_stmt|;
name|transform
operator|.
name|translate
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|transform
operator|.
name|scale
argument_list|(
literal|2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|transform
operator|.
name|shear
argument_list|(
literal|2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|setInputItemTransform
argument_list|(
name|transform
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|inputItemTransform
argument_list|()
argument_list|,
name|transform
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// reset
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|setInputItemTransform
argument_list|(
name|QTransform
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cursorRectangle
name|void
name|tst_qinputmethod
operator|::
name|cursorRectangle
parameter_list|()
block|{
name|QCOMPARE
argument_list|(
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|cursorRectangle
argument_list|()
argument_list|,
name|QRectF
argument_list|()
argument_list|)
expr_stmt|;
name|QTransform
name|transform
decl_stmt|;
name|transform
operator|.
name|translate
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|transform
operator|.
name|scale
argument_list|(
literal|2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|transform
operator|.
name|shear
argument_list|(
literal|2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|setInputItemTransform
argument_list|(
name|transform
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|setInputItem
argument_list|(
operator|&
name|m_inputItem
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|cursorRectangle
argument_list|()
argument_list|,
name|transform
operator|.
name|mapRect
argument_list|(
name|QRectF
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|m_inputItem
operator|.
name|cursorRectangle
operator|=
name|QRectF
argument_list|(
literal|1.5
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|cursorRectangle
argument_list|()
argument_list|,
name|transform
operator|.
name|mapRect
argument_list|(
name|QRectF
argument_list|(
literal|1.5
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|8
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|// reset
name|m_inputItem
operator|.
name|cursorRectangle
operator|=
name|QRectF
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|setInputItem
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|setInputItemTransform
argument_list|(
name|QTransform
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|invokeAction
name|void
name|tst_qinputmethod
operator|::
name|invokeAction
parameter_list|()
block|{
name|QCOMPARE
argument_list|(
name|m_platformInputContext
operator|.
name|m_action
argument_list|,
name|QInputMethod
operator|::
name|Click
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|m_platformInputContext
operator|.
name|m_cursorPosition
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|invokeAction
argument_list|(
name|QInputMethod
operator|::
name|ContextMenu
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|m_platformInputContext
operator|.
name|m_action
argument_list|,
name|QInputMethod
operator|::
name|ContextMenu
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|m_platformInputContext
operator|.
name|m_cursorPosition
argument_list|,
literal|5
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|reset
name|void
name|tst_qinputmethod
operator|::
name|reset
parameter_list|()
block|{
name|QCOMPARE
argument_list|(
name|m_platformInputContext
operator|.
name|m_resetCallCount
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|reset
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|m_platformInputContext
operator|.
name|m_resetCallCount
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|reset
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|m_platformInputContext
operator|.
name|m_resetCallCount
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|commit
name|void
name|tst_qinputmethod
operator|::
name|commit
parameter_list|()
block|{
name|QCOMPARE
argument_list|(
name|m_platformInputContext
operator|.
name|m_commitCallCount
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|commit
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|m_platformInputContext
operator|.
name|m_commitCallCount
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|commit
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|m_platformInputContext
operator|.
name|m_commitCallCount
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|update
name|void
name|tst_qinputmethod
operator|::
name|update
parameter_list|()
block|{
name|QCOMPARE
argument_list|(
name|m_platformInputContext
operator|.
name|m_updateCallCount
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|m_platformInputContext
operator|.
name|m_lastQueries
argument_list|)
argument_list|,
name|int
argument_list|(
name|Qt
operator|::
name|ImhNone
argument_list|)
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|update
argument_list|(
name|Qt
operator|::
name|ImQueryInput
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|m_platformInputContext
operator|.
name|m_updateCallCount
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|m_platformInputContext
operator|.
name|m_lastQueries
argument_list|)
argument_list|,
name|int
argument_list|(
name|Qt
operator|::
name|ImQueryInput
argument_list|)
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|update
argument_list|(
name|Qt
operator|::
name|ImQueryAll
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|m_platformInputContext
operator|.
name|m_updateCallCount
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|m_platformInputContext
operator|.
name|m_lastQueries
argument_list|)
argument_list|,
name|int
argument_list|(
name|Qt
operator|::
name|ImQueryAll
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|keyboardRectangle
argument_list|()
argument_list|,
name|QRectF
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
argument_list|)
expr_stmt|;
comment|// reset
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|setInputItem
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|query
name|void
name|tst_qinputmethod
operator|::
name|query
parameter_list|()
block|{
name|QInputMethodQueryEvent
name|query
argument_list|(
name|Qt
operator|::
name|InputMethodQueries
argument_list|(
name|Qt
operator|::
name|ImPreferredLanguage
operator||
name|Qt
operator|::
name|ImCursorRectangle
argument_list|)
argument_list|)
decl_stmt|;
name|QGuiApplication
operator|::
name|sendEvent
argument_list|(
operator|&
name|m_inputItem
argument_list|,
operator|&
name|query
argument_list|)
expr_stmt|;
name|QString
name|language
init|=
name|query
operator|.
name|value
argument_list|(
name|Qt
operator|::
name|ImPreferredLanguage
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|language
argument_list|,
name|QString
argument_list|(
literal|"English"
argument_list|)
argument_list|)
expr_stmt|;
name|QRect
name|cursorRectangle
init|=
name|query
operator|.
name|value
argument_list|(
name|Qt
operator|::
name|ImCursorRectangle
argument_list|)
operator|.
name|toRect
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|cursorRectangle
argument_list|,
name|QRect
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|inputDirection
name|void
name|tst_qinputmethod
operator|::
name|inputDirection
parameter_list|()
block|{
name|QCOMPARE
argument_list|(
name|m_platformInputContext
operator|.
name|m_inputDirectionCallCount
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|inputDirection
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|m_platformInputContext
operator|.
name|m_inputDirectionCallCount
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|m_platformInputContext
operator|.
name|m_localeCallCount
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|locale
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|m_platformInputContext
operator|.
name|m_localeCallCount
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_qinputmethod
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qinputmethod.moc"
end_include
end_unit
