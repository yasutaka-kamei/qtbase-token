begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_class
DECL|class|tst_QFlags
class|class
name|tst_QFlags
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|testFlag
parameter_list|()
specifier|const
function_decl|;
name|void
name|testFlagZeroFlag
parameter_list|()
specifier|const
function_decl|;
name|void
name|testFlagMultiBits
parameter_list|()
specifier|const
function_decl|;
name|void
name|constExpr
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|testFlag
name|void
name|tst_QFlags
operator|::
name|testFlag
parameter_list|()
specifier|const
block|{
name|Qt
operator|::
name|MouseButtons
name|btn
init|=
name|Qt
operator|::
name|LeftButton
operator||
name|Qt
operator|::
name|RightButton
decl_stmt|;
name|QVERIFY
argument_list|(
name|btn
operator|.
name|testFlag
argument_list|(
name|Qt
operator|::
name|LeftButton
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|btn
operator|.
name|testFlag
argument_list|(
name|Qt
operator|::
name|MidButton
argument_list|)
argument_list|)
expr_stmt|;
name|btn
operator|=
literal|0
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|btn
operator|.
name|testFlag
argument_list|(
name|Qt
operator|::
name|LeftButton
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testFlagZeroFlag
name|void
name|tst_QFlags
operator|::
name|testFlagZeroFlag
parameter_list|()
specifier|const
block|{
block|{
name|Qt
operator|::
name|MouseButtons
name|btn
init|=
name|Qt
operator|::
name|LeftButton
operator||
name|Qt
operator|::
name|RightButton
decl_stmt|;
comment|/* Qt::NoButton has the value 0. */
name|QVERIFY
argument_list|(
operator|!
name|btn
operator|.
name|testFlag
argument_list|(
name|Qt
operator|::
name|NoButton
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|{
comment|/* A zero enum set should test true with zero. */
name|QVERIFY
argument_list|(
name|Qt
operator|::
name|MouseButtons
argument_list|()
operator|.
name|testFlag
argument_list|(
name|Qt
operator|::
name|NoButton
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|{
name|Qt
operator|::
name|MouseButtons
name|btn
init|=
name|Qt
operator|::
name|NoButton
decl_stmt|;
name|QVERIFY
argument_list|(
name|btn
operator|.
name|testFlag
argument_list|(
name|Qt
operator|::
name|NoButton
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|testFlagMultiBits
name|void
name|tst_QFlags
operator|::
name|testFlagMultiBits
parameter_list|()
specifier|const
block|{
comment|/* Qt::Window is 0x00000001      * Qt::Dialog is 0x00000002 | Window      */
block|{
specifier|const
name|Qt
operator|::
name|WindowFlags
name|onlyWindow
argument_list|(
name|Qt
operator|::
name|Window
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|onlyWindow
operator|.
name|testFlag
argument_list|(
name|Qt
operator|::
name|Dialog
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|{
specifier|const
name|Qt
operator|::
name|WindowFlags
name|hasDialog
argument_list|(
name|Qt
operator|::
name|Dialog
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|hasDialog
operator|.
name|testFlag
argument_list|(
name|Qt
operator|::
name|Dialog
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|verifyConstExpr
template|template
parameter_list|<
name|int
name|N
parameter_list|,
name|typename
name|T
parameter_list|>
name|bool
name|verifyConstExpr
parameter_list|(
name|T
name|n
parameter_list|)
block|{
return|return
name|n
operator|==
name|N
return|;
block|}
end_function
begin_function
DECL|function|constExpr
name|void
name|tst_QFlags
operator|::
name|constExpr
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|Q_COMPILER_CONSTEXPR
name|Qt
operator|::
name|MouseButtons
name|btn
init|=
name|Qt
operator|::
name|LeftButton
operator||
name|Qt
operator|::
name|RightButton
decl_stmt|;
switch|switch
condition|(
name|btn
condition|)
block|{
case|case
name|Qt
operator|::
name|LeftButton
case|:
name|QVERIFY
argument_list|(
literal|false
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|RightButton
case|:
name|QVERIFY
argument_list|(
literal|false
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|LeftButton
operator||
name|Qt
operator|::
name|RightButton
case|:
name|QVERIFY
argument_list|(
literal|true
argument_list|)
expr_stmt|;
break|break;
default|default:
name|QVERIFY
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
name|QVERIFY
argument_list|(
name|verifyConstExpr
argument_list|<
operator|(
name|Qt
operator|::
name|LeftButton
operator||
name|Qt
operator|::
name|RightButton
operator|)
operator|&
name|Qt
operator|::
name|LeftButton
argument_list|>
argument_list|(
name|Qt
operator|::
name|LeftButton
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|verifyConstExpr
argument_list|<
operator|(
name|Qt
operator|::
name|LeftButton
operator||
name|Qt
operator|::
name|RightButton
operator|)
operator|&
name|Qt
operator|::
name|MiddleButton
argument_list|>
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|verifyConstExpr
argument_list|<
operator|(
name|Qt
operator|::
name|LeftButton
operator||
name|Qt
operator|::
name|RightButton
operator|)
operator||
name|Qt
operator|::
name|MiddleButton
argument_list|>
argument_list|(
name|Qt
operator|::
name|LeftButton
operator||
name|Qt
operator|::
name|RightButton
operator||
name|Qt
operator|::
name|MiddleButton
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|verifyConstExpr
operator|<
operator|~
operator|(
name|Qt
operator|::
name|LeftButton
operator||
name|Qt
operator|::
name|RightButton
operator|)
operator|>
operator|(
operator|~
operator|(
name|Qt
operator|::
name|LeftButton
operator||
name|Qt
operator|::
name|RightButton
operator|)
operator|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|verifyConstExpr
argument_list|<
name|Qt
operator|::
name|MouseButtons
operator|(
name|Qt
operator|::
name|LeftButton
operator|)
modifier|^
name|Qt
operator|::
name|RightButton
argument_list|>
argument_list|(
name|Qt
operator|::
name|LeftButton
operator|^
name|Qt
operator|::
name|RightButton
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|verifyConstExpr
argument_list|<
name|Qt
operator|::
name|MouseButtons
operator|(
literal|0
operator|)
argument_list|>
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|verifyConstExpr
argument_list|<
name|Qt
operator|::
name|MouseButtons
operator|(
name|Qt
operator|::
name|RightButton
operator|)
operator|&
literal|0xff
argument_list|>
argument_list|(
name|Qt
operator|::
name|RightButton
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|verifyConstExpr
argument_list|<
name|Qt
operator|::
name|MouseButtons
operator|(
name|Qt
operator|::
name|RightButton
operator|)
operator||
literal|0xff
argument_list|>
argument_list|(
literal|0xff
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|verifyConstExpr
argument_list|<
name|Qt
operator|::
name|RightButton
argument_list|>
argument_list|(
operator|!
name|Qt
operator|::
name|MouseButtons
argument_list|(
name|Qt
operator|::
name|LeftButton
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|// (statically) check QTypeInfo for QFlags instantiations:
end_comment
begin_enum
DECL|enum|MyEnum
DECL|enumerator|Zero
DECL|enumerator|One
DECL|enumerator|Two
DECL|enumerator|Four
enum|enum
name|MyEnum
block|{
name|Zero
block|,
name|One
block|,
name|Two
block|,
name|Four
init|=
literal|4
block|}
enum|;
end_enum
begin_expr_stmt
name|Q_DECLARE_FLAGS
argument_list|(
name|MyFlags
argument_list|,
name|MyEnum
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|MyFlags
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
name|MyFlags
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_STATIC_ASSERT
argument_list|(
operator|!
name|QTypeInfo
argument_list|<
name|MyFlags
argument_list|>
operator|::
name|isComplex
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_STATIC_ASSERT
argument_list|(
operator|!
name|QTypeInfo
argument_list|<
name|MyFlags
argument_list|>
operator|::
name|isStatic
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_STATIC_ASSERT
argument_list|(
operator|!
name|QTypeInfo
argument_list|<
name|MyFlags
argument_list|>
operator|::
name|isLarge
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_STATIC_ASSERT
argument_list|(
operator|!
name|QTypeInfo
argument_list|<
name|MyFlags
argument_list|>
operator|::
name|isPointer
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QFlags
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qflags.moc"
end_include
end_unit
