begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/private/qtestelementattribute_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*! \enum QTest::AttributeIndex   This enum numbers the different tests.    \value AI_Undefined    \value AI_Name    \value AI_Result    \value AI_Tests    \value AI_Failures    \value AI_Errors    \value AI_Type    \value AI_Description    \value AI_PropertyValue    \value AI_QTestVersion    \value AI_QtVersion    \value AI_File    \value AI_Line    \value AI_Metric    \value AI_Tag    \value AI_Value    \value AI_Iterations */
end_comment
begin_comment
comment|/*! \enum QTest::LogElementType   The enum specifies the kinds of test log messages.    \value LET_Undefined    \value LET_Property    \value LET_Properties    \value LET_Failure    \value LET_Error    \value LET_TestCase    \value LET_TestSuite    \value LET_Benchmark    \value LET_SystemError */
end_comment
begin_constructor
DECL|function|QTestElementAttribute
name|QTestElementAttribute
operator|::
name|QTestElementAttribute
parameter_list|()
member_init_list|:
name|attributeValue
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|attributeIndex
argument_list|(
name|QTest
operator|::
name|AI_Undefined
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QTestElementAttribute
name|QTestElementAttribute
operator|::
name|~
name|QTestElementAttribute
parameter_list|()
block|{
operator|delete
index|[]
name|attributeValue
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|value
specifier|const
name|char
modifier|*
name|QTestElementAttribute
operator|::
name|value
parameter_list|()
specifier|const
block|{
return|return
name|attributeValue
return|;
block|}
end_function
begin_function
DECL|function|name
specifier|const
name|char
modifier|*
name|QTestElementAttribute
operator|::
name|name
parameter_list|()
specifier|const
block|{
specifier|const
name|char
modifier|*
name|AttributeNames
index|[]
init|=
block|{
literal|"name"
block|,
literal|"result"
block|,
literal|"tests"
block|,
literal|"failures"
block|,
literal|"errors"
block|,
literal|"type"
block|,
literal|"description"
block|,
literal|"value"
block|,
literal|"qtestversion"
block|,
literal|"qtversion"
block|,
literal|"file"
block|,
literal|"line"
block|,
literal|"metric"
block|,
literal|"tag"
block|,
literal|"value"
block|,
literal|"iterations"
block|}
decl_stmt|;
if|if
condition|(
name|attributeIndex
operator|!=
name|QTest
operator|::
name|AI_Undefined
condition|)
return|return
name|AttributeNames
index|[
name|attributeIndex
index|]
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|index
name|QTest
operator|::
name|AttributeIndex
name|QTestElementAttribute
operator|::
name|index
parameter_list|()
specifier|const
block|{
return|return
name|attributeIndex
return|;
block|}
end_function
begin_function
DECL|function|isNull
name|bool
name|QTestElementAttribute
operator|::
name|isNull
parameter_list|()
specifier|const
block|{
return|return
name|attributeIndex
operator|==
name|QTest
operator|::
name|AI_Undefined
return|;
block|}
end_function
begin_function
DECL|function|setPair
name|bool
name|QTestElementAttribute
operator|::
name|setPair
parameter_list|(
name|QTest
operator|::
name|AttributeIndex
name|index
parameter_list|,
specifier|const
name|char
modifier|*
name|value
parameter_list|)
block|{
if|if
condition|(
operator|!
name|value
condition|)
return|return
literal|false
return|;
operator|delete
index|[]
name|attributeValue
expr_stmt|;
name|attributeIndex
operator|=
name|index
expr_stmt|;
name|attributeValue
operator|=
name|qstrdup
argument_list|(
name|value
argument_list|)
expr_stmt|;
return|return
name|attributeValue
operator|!=
literal|0
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
