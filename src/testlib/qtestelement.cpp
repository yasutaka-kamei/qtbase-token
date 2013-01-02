begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/private/qtestelement_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QTestElement
name|QTestElement
operator|::
name|QTestElement
parameter_list|(
name|int
name|type
parameter_list|)
member_init_list|:
name|QTestCoreElement
argument_list|<
name|QTestElement
argument_list|>
argument_list|(
name|type
argument_list|)
member_init_list|,
name|listOfChildren
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|parent
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QTestElement
name|QTestElement
operator|::
name|~
name|QTestElement
parameter_list|()
block|{
operator|delete
name|listOfChildren
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|addLogElement
name|bool
name|QTestElement
operator|::
name|addLogElement
parameter_list|(
name|QTestElement
modifier|*
name|element
parameter_list|)
block|{
if|if
condition|(
operator|!
name|element
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|element
operator|->
name|elementType
argument_list|()
operator|!=
name|QTest
operator|::
name|LET_Undefined
condition|)
block|{
name|element
operator|->
name|addToList
argument_list|(
operator|&
name|listOfChildren
argument_list|)
expr_stmt|;
name|element
operator|->
name|setParent
argument_list|(
name|this
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|childElements
name|QTestElement
modifier|*
name|QTestElement
operator|::
name|childElements
parameter_list|()
specifier|const
block|{
return|return
name|listOfChildren
return|;
block|}
end_function
begin_function
DECL|function|parentElement
specifier|const
name|QTestElement
modifier|*
name|QTestElement
operator|::
name|parentElement
parameter_list|()
specifier|const
block|{
return|return
name|parent
return|;
block|}
end_function
begin_function
DECL|function|setParent
name|void
name|QTestElement
operator|::
name|setParent
parameter_list|(
specifier|const
name|QTestElement
modifier|*
name|p
parameter_list|)
block|{
name|parent
operator|=
name|p
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
