begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
name|void
name|signedness
parameter_list|()
function_decl|;
name|void
name|classEnum
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
name|int
argument_list|(
name|Qt
operator|::
name|LeftButton
operator||
name|Qt
operator|::
name|RightButton
argument_list|)
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
begin_function
DECL|function|signedness
name|void
name|tst_QFlags
operator|::
name|signedness
parameter_list|()
block|{
comment|// these are all 'true' on GCC, but since the std says the
comment|// underlying type is implementation-defined, we need to allow for
comment|// a different signedness, so we only check that the relative
comment|// signedness of the types matches:
name|Q_STATIC_ASSERT
argument_list|(
operator|(
name|QtPrivate
operator|::
name|is_unsigned
argument_list|<
name|Qt
operator|::
name|MouseButton
argument_list|>
operator|::
name|value
operator|==
name|QtPrivate
operator|::
name|is_unsigned
argument_list|<
name|Qt
operator|::
name|MouseButtons
operator|::
name|Int
argument_list|>
operator|::
name|value
operator|)
argument_list|)
expr_stmt|;
name|Q_STATIC_ASSERT
argument_list|(
operator|(
name|QtPrivate
operator|::
name|is_signed
argument_list|<
name|Qt
operator|::
name|AlignmentFlag
argument_list|>
operator|::
name|value
operator|==
name|QtPrivate
operator|::
name|is_signed
argument_list|<
name|Qt
operator|::
name|Alignment
operator|::
name|Int
argument_list|>
operator|::
name|value
operator|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_COMPILER_CLASS_ENUM
argument_list|)
end_if
begin_enum
DECL|class|MyStrictEnum
DECL|member|StrictZero
DECL|member|StrictOne
DECL|member|StrictTwo
DECL|member|StrictFour
enum|enum class
name|MyStrictEnum
block|{
name|StrictZero
block|,
name|StrictOne
block|,
name|StrictTwo
block|,
name|StrictFour
init|=
literal|4
block|}
enum|;
end_enum
begin_macro
name|Q_DECLARE_FLAGS
argument_list|(
argument|MyStrictFlags
argument_list|,
argument|MyStrictEnum
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|MyStrictFlags
argument_list|)
end_macro
begin_expr_stmt
name|Q_STATIC_ASSERT
argument_list|(
operator|!
name|QTypeInfo
argument_list|<
name|MyStrictFlags
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
name|MyStrictFlags
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
name|MyStrictFlags
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
name|MyStrictFlags
argument_list|>
operator|::
name|isPointer
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|classEnum
name|void
name|tst_QFlags
operator|::
name|classEnum
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_COMPILER_CLASS_ENUM
argument_list|)
comment|// The main aim of the test is making sure it compiles
comment|// The QCOMPARE are there as an extra
name|MyStrictEnum
name|e1
init|=
name|MyStrictEnum
operator|::
name|StrictOne
decl_stmt|;
name|MyStrictEnum
name|e2
init|=
name|MyStrictEnum
operator|::
name|StrictTwo
decl_stmt|;
name|MyStrictFlags
name|f1
argument_list|(
name|MyStrictEnum
operator|::
name|StrictOne
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|f1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|MyStrictFlags
name|f2
argument_list|(
name|e2
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|f2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|MyStrictFlags
name|f0
decl_stmt|;
name|QCOMPARE
argument_list|(
name|f0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|MyStrictFlags
name|f3
argument_list|(
name|e2
operator||
name|e1
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|f3
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|f3
operator|.
name|testFlag
argument_list|(
name|MyStrictEnum
operator|::
name|StrictOne
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|f1
operator|.
name|testFlag
argument_list|(
name|MyStrictEnum
operator|::
name|StrictTwo
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|f0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|f3
operator|&
name|int
argument_list|(
literal|1
argument_list|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|f3
operator|&
name|uint
argument_list|(
literal|1
argument_list|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|f3
operator|&
name|MyStrictEnum
operator|::
name|StrictOne
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|MyStrictFlags
name|aux
decl_stmt|;
name|aux
operator|=
name|f3
expr_stmt|;
name|aux
operator|&=
name|int
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|aux
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|aux
operator|=
name|f3
expr_stmt|;
name|aux
operator|&=
name|uint
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|aux
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|aux
operator|=
name|f3
expr_stmt|;
name|aux
operator|&=
name|MyStrictEnum
operator|::
name|StrictOne
expr_stmt|;
name|QCOMPARE
argument_list|(
name|aux
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|aux
operator|=
name|f3
expr_stmt|;
name|aux
operator|&=
name|f1
expr_stmt|;
name|QCOMPARE
argument_list|(
name|aux
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|aux
operator|=
name|f3
operator|^
name|f3
expr_stmt|;
name|QCOMPARE
argument_list|(
name|aux
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|aux
operator|=
name|f3
operator|^
name|f1
expr_stmt|;
name|QCOMPARE
argument_list|(
name|aux
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|aux
operator|=
name|f3
operator|^
name|f0
expr_stmt|;
name|QCOMPARE
argument_list|(
name|aux
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|aux
operator|=
name|f3
operator|^
name|MyStrictEnum
operator|::
name|StrictOne
expr_stmt|;
name|QCOMPARE
argument_list|(
name|aux
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|aux
operator|=
name|f3
operator|^
name|MyStrictEnum
operator|::
name|StrictZero
expr_stmt|;
name|QCOMPARE
argument_list|(
name|aux
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|aux
operator|=
name|f3
expr_stmt|;
name|aux
operator|^=
name|f3
expr_stmt|;
name|QCOMPARE
argument_list|(
name|aux
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|aux
operator|=
name|f3
expr_stmt|;
name|aux
operator|^=
name|f1
expr_stmt|;
name|QCOMPARE
argument_list|(
name|aux
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|aux
operator|=
name|f3
expr_stmt|;
name|aux
operator|^=
name|f0
expr_stmt|;
name|QCOMPARE
argument_list|(
name|aux
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|aux
operator|=
name|f3
expr_stmt|;
name|aux
operator|^=
name|MyStrictEnum
operator|::
name|StrictOne
expr_stmt|;
name|QCOMPARE
argument_list|(
name|aux
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|aux
operator|=
name|f3
expr_stmt|;
name|aux
operator|^=
name|MyStrictEnum
operator|::
name|StrictZero
expr_stmt|;
name|QCOMPARE
argument_list|(
name|aux
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|aux
operator|=
name|f1
operator||
name|f2
expr_stmt|;
name|QCOMPARE
argument_list|(
name|aux
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|aux
operator|=
name|MyStrictEnum
operator|::
name|StrictOne
operator||
name|MyStrictEnum
operator|::
name|StrictTwo
expr_stmt|;
name|QCOMPARE
argument_list|(
name|aux
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|aux
operator|=
name|f1
expr_stmt|;
name|aux
operator||=
name|f2
expr_stmt|;
name|QCOMPARE
argument_list|(
name|aux
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|aux
operator|=
name|MyStrictEnum
operator|::
name|StrictOne
expr_stmt|;
name|aux
operator||=
name|MyStrictEnum
operator|::
name|StrictTwo
expr_stmt|;
name|QCOMPARE
argument_list|(
name|aux
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|aux
operator|=
operator|~
name|f1
expr_stmt|;
name|QCOMPARE
argument_list|(
name|aux
argument_list|,
operator|-
literal|2
argument_list|)
expr_stmt|;
comment|// Just to make sure it compiles
if|if
condition|(
literal|false
condition|)
name|qDebug
argument_list|()
operator|<<
name|f3
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
begin_macro
name|Q_DECLARE_FLAGS
argument_list|(
argument|MyFlags
argument_list|,
argument|MyEnum
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|MyFlags
argument_list|)
end_macro
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
