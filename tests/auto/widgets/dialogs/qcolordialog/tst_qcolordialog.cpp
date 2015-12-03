begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtGui/QtGui>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QColorDialog>
end_include
begin_macro
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QtTestEventThread
argument_list|)
end_macro
begin_class
DECL|class|tst_QColorDialog
class|class
name|tst_QColorDialog
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QColorDialog
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QColorDialog
parameter_list|()
destructor_decl|;
public|public
name|slots
public|:
name|void
name|postKeyReturn
parameter_list|()
function_decl|;
name|void
name|testGetRgba
parameter_list|()
function_decl|;
name|void
name|testNativeActiveModalWidget
parameter_list|()
function_decl|;
private|private
name|slots
private|:
name|void
name|defaultOkButton
parameter_list|()
function_decl|;
name|void
name|native_activeModalWidget
parameter_list|()
function_decl|;
name|void
name|task247349_alpha
parameter_list|()
function_decl|;
name|void
name|QTBUG_43548_initialColor
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_class
DECL|class|TestNativeDialog
class|class
name|TestNativeDialog
super|:
specifier|public
name|QColorDialog
block|{
name|Q_OBJECT
public|public:
DECL|member|m_activeModalWidget
name|QWidget
modifier|*
name|m_activeModalWidget
decl_stmt|;
DECL|function|TestNativeDialog
name|TestNativeDialog
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QColorDialog
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_activeModalWidget
argument_list|(
literal|0
argument_list|)
block|{
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|1
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|test_activeModalWidgetSignal
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
public|public
name|slots
public|:
DECL|function|test_activeModalWidgetSignal
name|void
name|test_activeModalWidgetSignal
parameter_list|()
block|{
name|m_activeModalWidget
operator|=
name|qApp
operator|->
name|activeModalWidget
argument_list|()
expr_stmt|;
block|}
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QColorDialog
name|tst_QColorDialog
operator|::
name|tst_QColorDialog
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QColorDialog
name|tst_QColorDialog
operator|::
name|~
name|tst_QColorDialog
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|testNativeActiveModalWidget
name|void
name|tst_QColorDialog
operator|::
name|testNativeActiveModalWidget
parameter_list|()
block|{
comment|// Check that QApplication::activeModalWidget retruns the
comment|// color dialog when it is executing, even when using a native
comment|// dialog:
name|TestNativeDialog
name|d
decl_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|1000
argument_list|,
operator|&
name|d
argument_list|,
name|SLOT
argument_list|(
name|hide
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|.
name|exec
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|&
name|d
argument_list|,
name|d
operator|.
name|m_activeModalWidget
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|native_activeModalWidget
name|void
name|tst_QColorDialog
operator|::
name|native_activeModalWidget
parameter_list|()
block|{
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|3000
argument_list|,
name|qApp
argument_list|,
name|SLOT
argument_list|(
name|quit
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|0
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|testNativeActiveModalWidget
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|exec
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|postKeyReturn
name|void
name|tst_QColorDialog
operator|::
name|postKeyReturn
parameter_list|()
block|{
name|QWidgetList
name|list
init|=
name|QApplication
operator|::
name|topLevelWidgets
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|list
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QColorDialog
modifier|*
name|dialog
init|=
name|qobject_cast
argument_list|<
name|QColorDialog
operator|*
argument_list|>
argument_list|(
name|list
index|[
name|i
index|]
argument_list|)
decl_stmt|;
if|if
condition|(
name|dialog
condition|)
block|{
name|QTest
operator|::
name|keyClick
argument_list|(
name|list
index|[
name|i
index|]
argument_list|,
name|Qt
operator|::
name|Key_Return
argument_list|,
name|Qt
operator|::
name|NoModifier
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
block|}
end_function
begin_function
DECL|function|testGetRgba
name|void
name|tst_QColorDialog
operator|::
name|testGetRgba
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|Q_OS_MAC
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"Sending QTest::keyClick to OSX color dialog helper fails, see QTBUG-24320"
argument_list|,
name|Continue
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|bool
name|ok
init|=
literal|false
decl_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|500
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|postKeyReturn
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QColorDialog
operator|::
name|getRgba
argument_list|(
literal|0xffffffff
argument_list|,
operator|&
name|ok
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|ok
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|defaultOkButton
name|void
name|tst_QColorDialog
operator|::
name|defaultOkButton
parameter_list|()
block|{
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|4000
argument_list|,
name|qApp
argument_list|,
name|SLOT
argument_list|(
name|quit
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|0
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|testGetRgba
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|exec
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|task247349_alpha
name|void
name|tst_QColorDialog
operator|::
name|task247349_alpha
parameter_list|()
block|{
name|QColorDialog
name|dialog
decl_stmt|;
name|dialog
operator|.
name|setOption
argument_list|(
name|QColorDialog
operator|::
name|ShowAlphaChannel
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|int
name|alpha
init|=
literal|0x17
decl_stmt|;
name|dialog
operator|.
name|setCurrentColor
argument_list|(
name|QColor
argument_list|(
literal|0x01
argument_list|,
literal|0x02
argument_list|,
literal|0x03
argument_list|,
name|alpha
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|alpha
argument_list|,
name|dialog
operator|.
name|currentColor
argument_list|()
operator|.
name|alpha
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|alpha
argument_list|,
name|qAlpha
argument_list|(
name|dialog
operator|.
name|currentColor
argument_list|()
operator|.
name|rgba
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|QTBUG_43548_initialColor
name|void
name|tst_QColorDialog
operator|::
name|QTBUG_43548_initialColor
parameter_list|()
block|{
name|QColorDialog
name|dialog
decl_stmt|;
name|dialog
operator|.
name|setOption
argument_list|(
name|QColorDialog
operator|::
name|DontUseNativeDialog
argument_list|)
expr_stmt|;
name|dialog
operator|.
name|setCurrentColor
argument_list|(
name|QColor
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
argument_list|)
expr_stmt|;
name|QColor
name|a
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|a
argument_list|,
name|dialog
operator|.
name|currentColor
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QColorDialog
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qcolordialog.moc"
end_include
end_unit
