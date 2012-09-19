begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmetatype.h>
end_include
begin_class
DECL|class|tst_QMetaType
class|class
name|tst_QMetaType
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QMetaType
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QMetaType
parameter_list|()
destructor_decl|;
private|private
name|slots
private|:
name|void
name|typeBuiltin_data
parameter_list|()
function_decl|;
name|void
name|typeBuiltin
parameter_list|()
function_decl|;
name|void
name|typeBuiltinNotNormalized_data
parameter_list|()
function_decl|;
name|void
name|typeBuiltinNotNormalized
parameter_list|()
function_decl|;
name|void
name|typeCustom
parameter_list|()
function_decl|;
name|void
name|typeCustomNotNormalized
parameter_list|()
function_decl|;
name|void
name|typeNotRegistered
parameter_list|()
function_decl|;
name|void
name|typeNotRegisteredNotNormalized
parameter_list|()
function_decl|;
name|void
name|typeNameBuiltin_data
parameter_list|()
function_decl|;
name|void
name|typeNameBuiltin
parameter_list|()
function_decl|;
name|void
name|typeNameCustom
parameter_list|()
function_decl|;
name|void
name|typeNameNotRegistered
parameter_list|()
function_decl|;
name|void
name|isRegisteredBuiltin_data
parameter_list|()
function_decl|;
name|void
name|isRegisteredBuiltin
parameter_list|()
function_decl|;
name|void
name|isRegisteredCustom
parameter_list|()
function_decl|;
name|void
name|isRegisteredNotRegistered
parameter_list|()
function_decl|;
name|void
name|constructCoreType_data
parameter_list|()
function_decl|;
name|void
name|constructCoreType
parameter_list|()
function_decl|;
name|void
name|constructCoreTypeStaticLess_data
parameter_list|()
function_decl|;
name|void
name|constructCoreTypeStaticLess
parameter_list|()
function_decl|;
name|void
name|constructCoreTypeCopy_data
parameter_list|()
function_decl|;
name|void
name|constructCoreTypeCopy
parameter_list|()
function_decl|;
name|void
name|constructCustomType_data
parameter_list|()
function_decl|;
name|void
name|constructCustomType
parameter_list|()
function_decl|;
name|void
name|constructInPlace_data
parameter_list|()
function_decl|;
name|void
name|constructInPlace
parameter_list|()
function_decl|;
name|void
name|constructInPlaceCopy_data
parameter_list|()
function_decl|;
name|void
name|constructInPlaceCopy
parameter_list|()
function_decl|;
name|void
name|constructInPlaceCopyStaticLess_data
parameter_list|()
function_decl|;
name|void
name|constructInPlaceCopyStaticLess
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QMetaType
name|tst_QMetaType
operator|::
name|tst_QMetaType
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QMetaType
name|tst_QMetaType
operator|::
name|~
name|tst_QMetaType
parameter_list|()
block|{ }
end_destructor
begin_struct
DECL|struct|BigClass
struct|struct
name|BigClass
block|{
DECL|member|n
DECL|member|i
DECL|member|e
DECL|member|r
DECL|member|o
DECL|member|b
name|double
name|n
decl_stmt|,
name|i
decl_stmt|,
name|e
decl_stmt|,
name|r
decl_stmt|,
name|o
decl_stmt|,
name|b
decl_stmt|;
block|}
struct|;
end_struct
begin_expr_stmt
DECL|variable|BigClass
name|Q_DECLARE_METATYPE
argument_list|(
name|BigClass
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function
DECL|function|typeBuiltin_data
name|void
name|tst_QMetaType
operator|::
name|typeBuiltin_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QByteArray
argument_list|>
argument_list|(
literal|"typeName"
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|QMetaType
operator|::
name|User
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|char
modifier|*
name|name
init|=
name|QMetaType
operator|::
name|typeName
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|name
condition|)
name|QTest
operator|::
name|newRow
argument_list|(
name|name
argument_list|)
operator|<<
name|QByteArray
argument_list|(
name|name
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|typeBuiltin
name|void
name|tst_QMetaType
operator|::
name|typeBuiltin
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QByteArray
argument_list|,
name|typeName
argument_list|)
expr_stmt|;
specifier|const
name|char
modifier|*
name|nm
init|=
name|typeName
operator|.
name|constData
argument_list|()
decl_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|100000
condition|;
operator|++
name|i
control|)
name|QMetaType
operator|::
name|type
argument_list|(
name|nm
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|typeBuiltinNotNormalized_data
name|void
name|tst_QMetaType
operator|::
name|typeBuiltinNotNormalized_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QByteArray
argument_list|>
argument_list|(
literal|"typeName"
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|QMetaType
operator|::
name|User
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|char
modifier|*
name|name
init|=
name|QMetaType
operator|::
name|typeName
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|name
condition|)
name|QTest
operator|::
name|newRow
argument_list|(
name|name
argument_list|)
operator|<<
name|QByteArray
argument_list|(
name|name
argument_list|)
operator|.
name|append
argument_list|(
literal|" "
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|typeBuiltinNotNormalized
name|void
name|tst_QMetaType
operator|::
name|typeBuiltinNotNormalized
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QByteArray
argument_list|,
name|typeName
argument_list|)
expr_stmt|;
specifier|const
name|char
modifier|*
name|nm
init|=
name|typeName
operator|.
name|constData
argument_list|()
decl_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|10000
condition|;
operator|++
name|i
control|)
name|QMetaType
operator|::
name|type
argument_list|(
name|nm
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_struct
DECL|struct|Foo
DECL|member|i
struct|struct
name|Foo
block|{
name|int
name|i
decl_stmt|;
block|}
struct|;
end_struct
begin_function
DECL|function|typeCustom
name|void
name|tst_QMetaType
operator|::
name|typeCustom
parameter_list|()
block|{
name|qRegisterMetaType
argument_list|<
name|Foo
argument_list|>
argument_list|(
literal|"Foo"
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|10000
condition|;
operator|++
name|i
control|)
name|QMetaType
operator|::
name|type
argument_list|(
literal|"Foo"
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|typeCustomNotNormalized
name|void
name|tst_QMetaType
operator|::
name|typeCustomNotNormalized
parameter_list|()
block|{
name|qRegisterMetaType
argument_list|<
name|Foo
argument_list|>
argument_list|(
literal|"Foo"
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|10000
condition|;
operator|++
name|i
control|)
name|QMetaType
operator|::
name|type
argument_list|(
literal|"Foo "
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|typeNotRegistered
name|void
name|tst_QMetaType
operator|::
name|typeNotRegistered
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
name|QMetaType
operator|::
name|type
argument_list|(
literal|"Bar"
argument_list|)
operator|==
literal|0
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|10000
condition|;
operator|++
name|i
control|)
name|QMetaType
operator|::
name|type
argument_list|(
literal|"Bar"
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|typeNotRegisteredNotNormalized
name|void
name|tst_QMetaType
operator|::
name|typeNotRegisteredNotNormalized
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
name|QMetaType
operator|::
name|type
argument_list|(
literal|"Bar"
argument_list|)
operator|==
literal|0
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|10000
condition|;
operator|++
name|i
control|)
name|QMetaType
operator|::
name|type
argument_list|(
literal|"Bar "
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|typeNameBuiltin_data
name|void
name|tst_QMetaType
operator|::
name|typeNameBuiltin_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"type"
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|QMetaType
operator|::
name|User
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|char
modifier|*
name|name
init|=
name|QMetaType
operator|::
name|typeName
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|name
condition|)
name|QTest
operator|::
name|newRow
argument_list|(
name|name
argument_list|)
operator|<<
name|i
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|typeNameBuiltin
name|void
name|tst_QMetaType
operator|::
name|typeNameBuiltin
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|type
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|500000
condition|;
operator|++
name|i
control|)
name|QMetaType
operator|::
name|typeName
argument_list|(
name|type
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|typeNameCustom
name|void
name|tst_QMetaType
operator|::
name|typeNameCustom
parameter_list|()
block|{
name|int
name|type
init|=
name|qRegisterMetaType
argument_list|<
name|Foo
argument_list|>
argument_list|(
literal|"Foo"
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|100000
condition|;
operator|++
name|i
control|)
name|QMetaType
operator|::
name|typeName
argument_list|(
name|type
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|typeNameNotRegistered
name|void
name|tst_QMetaType
operator|::
name|typeNameNotRegistered
parameter_list|()
block|{
comment|// We don't care much about this case, but test it anyway.
name|Q_ASSERT
argument_list|(
name|QMetaType
operator|::
name|typeName
argument_list|(
operator|-
literal|1
argument_list|)
operator|==
literal|0
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|500000
condition|;
operator|++
name|i
control|)
name|QMetaType
operator|::
name|typeName
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|isRegisteredBuiltin_data
name|void
name|tst_QMetaType
operator|::
name|isRegisteredBuiltin_data
parameter_list|()
block|{
name|typeNameBuiltin_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isRegisteredBuiltin
name|void
name|tst_QMetaType
operator|::
name|isRegisteredBuiltin
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|type
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|500000
condition|;
operator|++
name|i
control|)
name|QMetaType
operator|::
name|isRegistered
argument_list|(
name|type
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|isRegisteredCustom
name|void
name|tst_QMetaType
operator|::
name|isRegisteredCustom
parameter_list|()
block|{
name|int
name|type
init|=
name|qRegisterMetaType
argument_list|<
name|Foo
argument_list|>
argument_list|(
literal|"Foo"
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|100000
condition|;
operator|++
name|i
control|)
name|QMetaType
operator|::
name|isRegistered
argument_list|(
name|type
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|isRegisteredNotRegistered
name|void
name|tst_QMetaType
operator|::
name|isRegisteredNotRegistered
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
name|QMetaType
operator|::
name|typeName
argument_list|(
operator|-
literal|1
argument_list|)
operator|==
literal|0
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|100000
condition|;
operator|++
name|i
control|)
name|QMetaType
operator|::
name|isRegistered
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|constructCoreType_data
name|void
name|tst_QMetaType
operator|::
name|constructCoreType_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"typeId"
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
name|QMetaType
operator|::
name|FirstCoreType
init|;
name|i
operator|<=
name|QMetaType
operator|::
name|LastCoreType
condition|;
operator|++
name|i
control|)
name|QTest
operator|::
name|newRow
argument_list|(
name|QMetaType
operator|::
name|typeName
argument_list|(
name|i
argument_list|)
argument_list|)
operator|<<
name|i
expr_stmt|;
comment|// GUI types are tested in tst_QGuiMetaType.
block|}
end_function
begin_comment
comment|// Tests how fast QMetaType can default-construct and destroy a Qt
end_comment
begin_comment
comment|// core type. The purpose of this benchmark is to measure the overhead
end_comment
begin_comment
comment|// of using type id-based creation compared to creating the type
end_comment
begin_comment
comment|// directly (i.e. "T *t = new T(); delete t;").
end_comment
begin_function
DECL|function|constructCoreType
name|void
name|tst_QMetaType
operator|::
name|constructCoreType
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|typeId
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|100000
condition|;
operator|++
name|i
control|)
block|{
name|void
modifier|*
name|data
init|=
name|QMetaType
operator|::
name|create
argument_list|(
name|typeId
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
decl_stmt|;
name|QMetaType
operator|::
name|destroy
argument_list|(
name|typeId
argument_list|,
name|data
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|constructCoreTypeStaticLess_data
name|void
name|tst_QMetaType
operator|::
name|constructCoreTypeStaticLess_data
parameter_list|()
block|{
name|constructCoreType_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|constructCoreTypeStaticLess
name|void
name|tst_QMetaType
operator|::
name|constructCoreTypeStaticLess
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|typeId
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|QMetaType
name|type
argument_list|(
name|typeId
argument_list|)
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
literal|100000
condition|;
operator|++
name|i
control|)
block|{
name|void
modifier|*
name|data
init|=
name|type
operator|.
name|create
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
decl_stmt|;
name|type
operator|.
name|destroy
argument_list|(
name|data
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|constructCoreTypeCopy_data
name|void
name|tst_QMetaType
operator|::
name|constructCoreTypeCopy_data
parameter_list|()
block|{
name|constructCoreType_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|// Tests how fast QMetaType can copy-construct and destroy a Qt core
end_comment
begin_comment
comment|// type. The purpose of this benchmark is to measure the overhead of
end_comment
begin_comment
comment|// using type id-based creation compared to creating the type directly
end_comment
begin_comment
comment|// (i.e. "T *t = new T(other); delete t;").
end_comment
begin_function
DECL|function|constructCoreTypeCopy
name|void
name|tst_QMetaType
operator|::
name|constructCoreTypeCopy
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|typeId
argument_list|)
expr_stmt|;
name|QVariant
name|other
argument_list|(
name|typeId
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
decl_stmt|;
specifier|const
name|void
modifier|*
name|copy
init|=
name|other
operator|.
name|constData
argument_list|()
decl_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|100000
condition|;
operator|++
name|i
control|)
block|{
name|void
modifier|*
name|data
init|=
name|QMetaType
operator|::
name|create
argument_list|(
name|typeId
argument_list|,
name|copy
argument_list|)
decl_stmt|;
name|QMetaType
operator|::
name|destroy
argument_list|(
name|typeId
argument_list|,
name|data
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|constructCustomType_data
name|void
name|tst_QMetaType
operator|::
name|constructCustomType_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"typeId"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"BigClass"
argument_list|)
operator|<<
name|qMetaTypeId
argument_list|<
name|BigClass
argument_list|>
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|constructCustomType
name|void
name|tst_QMetaType
operator|::
name|constructCustomType
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|typeId
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|100000
condition|;
operator|++
name|i
control|)
block|{
name|void
modifier|*
name|data
init|=
name|QMetaType
operator|::
name|create
argument_list|(
name|typeId
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
decl_stmt|;
name|QMetaType
operator|::
name|destroy
argument_list|(
name|typeId
argument_list|,
name|data
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|constructInPlace_data
name|void
name|tst_QMetaType
operator|::
name|constructInPlace_data
parameter_list|()
block|{
name|constructCoreType_data
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"custom"
argument_list|)
operator|<<
name|qMetaTypeId
argument_list|<
name|BigClass
argument_list|>
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|constructInPlace
name|void
name|tst_QMetaType
operator|::
name|constructInPlace
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|typeId
argument_list|)
expr_stmt|;
name|int
name|size
init|=
name|QMetaType
operator|::
name|sizeOf
argument_list|(
name|typeId
argument_list|)
decl_stmt|;
name|void
modifier|*
name|storage
init|=
name|qMallocAligned
argument_list|(
name|size
argument_list|,
literal|2
operator|*
sizeof|sizeof
argument_list|(
name|qlonglong
argument_list|)
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|QMetaType
operator|::
name|construct
argument_list|(
name|typeId
argument_list|,
name|storage
argument_list|,
comment|/*copy=*/
literal|0
argument_list|)
argument_list|,
name|storage
argument_list|)
expr_stmt|;
name|QMetaType
operator|::
name|destruct
argument_list|(
name|typeId
argument_list|,
name|storage
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|100000
condition|;
operator|++
name|i
control|)
block|{
name|QMetaType
operator|::
name|construct
argument_list|(
name|typeId
argument_list|,
name|storage
argument_list|,
comment|/*copy=*/
literal|0
argument_list|)
expr_stmt|;
name|QMetaType
operator|::
name|destruct
argument_list|(
name|typeId
argument_list|,
name|storage
argument_list|)
expr_stmt|;
block|}
block|}
name|qFreeAligned
argument_list|(
name|storage
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|constructInPlaceCopy_data
name|void
name|tst_QMetaType
operator|::
name|constructInPlaceCopy_data
parameter_list|()
block|{
name|constructInPlace_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|constructInPlaceCopy
name|void
name|tst_QMetaType
operator|::
name|constructInPlaceCopy
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|typeId
argument_list|)
expr_stmt|;
name|int
name|size
init|=
name|QMetaType
operator|::
name|sizeOf
argument_list|(
name|typeId
argument_list|)
decl_stmt|;
name|void
modifier|*
name|storage
init|=
name|qMallocAligned
argument_list|(
name|size
argument_list|,
literal|2
operator|*
sizeof|sizeof
argument_list|(
name|qlonglong
argument_list|)
argument_list|)
decl_stmt|;
name|void
modifier|*
name|other
init|=
name|QMetaType
operator|::
name|create
argument_list|(
name|typeId
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|QMetaType
operator|::
name|construct
argument_list|(
name|typeId
argument_list|,
name|storage
argument_list|,
name|other
argument_list|)
argument_list|,
name|storage
argument_list|)
expr_stmt|;
name|QMetaType
operator|::
name|destruct
argument_list|(
name|typeId
argument_list|,
name|storage
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|100000
condition|;
operator|++
name|i
control|)
block|{
name|QMetaType
operator|::
name|construct
argument_list|(
name|typeId
argument_list|,
name|storage
argument_list|,
name|other
argument_list|)
expr_stmt|;
name|QMetaType
operator|::
name|destruct
argument_list|(
name|typeId
argument_list|,
name|storage
argument_list|)
expr_stmt|;
block|}
block|}
name|QMetaType
operator|::
name|destroy
argument_list|(
name|typeId
argument_list|,
name|other
argument_list|)
expr_stmt|;
name|qFreeAligned
argument_list|(
name|storage
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|constructInPlaceCopyStaticLess_data
name|void
name|tst_QMetaType
operator|::
name|constructInPlaceCopyStaticLess_data
parameter_list|()
block|{
name|constructInPlaceCopy_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|constructInPlaceCopyStaticLess
name|void
name|tst_QMetaType
operator|::
name|constructInPlaceCopyStaticLess
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|typeId
argument_list|)
expr_stmt|;
name|int
name|size
init|=
name|QMetaType
operator|::
name|sizeOf
argument_list|(
name|typeId
argument_list|)
decl_stmt|;
name|void
modifier|*
name|storage
init|=
name|qMallocAligned
argument_list|(
name|size
argument_list|,
literal|2
operator|*
sizeof|sizeof
argument_list|(
name|qlonglong
argument_list|)
argument_list|)
decl_stmt|;
name|void
modifier|*
name|other
init|=
name|QMetaType
operator|::
name|create
argument_list|(
name|typeId
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|QMetaType
operator|::
name|construct
argument_list|(
name|typeId
argument_list|,
name|storage
argument_list|,
name|other
argument_list|)
argument_list|,
name|storage
argument_list|)
expr_stmt|;
name|QMetaType
operator|::
name|destruct
argument_list|(
name|typeId
argument_list|,
name|storage
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|QMetaType
name|type
argument_list|(
name|typeId
argument_list|)
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
literal|100000
condition|;
operator|++
name|i
control|)
block|{
name|type
operator|.
name|construct
argument_list|(
name|storage
argument_list|,
name|other
argument_list|)
expr_stmt|;
name|type
operator|.
name|destruct
argument_list|(
name|storage
argument_list|)
expr_stmt|;
block|}
block|}
name|QMetaType
operator|::
name|destroy
argument_list|(
name|typeId
argument_list|,
name|other
argument_list|)
expr_stmt|;
name|qFreeAligned
argument_list|(
name|storage
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QMetaType
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qmetatype.moc"
end_include
end_unit
