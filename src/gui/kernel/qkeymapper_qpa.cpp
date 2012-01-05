begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qkeymapper_p.h"
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<private/qevent_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qlocale_p.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
name|QT_USE_NAMESPACE
DECL|function|QKeyMapperPrivate
name|QKeyMapperPrivate
operator|::
name|QKeyMapperPrivate
parameter_list|()
block|{
name|keyboardInputLocale
operator|=
name|QLocale
operator|::
name|system
argument_list|()
expr_stmt|;
name|keyboardInputDirection
operator|=
name|keyboardInputLocale
operator|.
name|textDirection
argument_list|()
expr_stmt|;
block|}
end_function
begin_destructor
DECL|function|~QKeyMapperPrivate
name|QKeyMapperPrivate
operator|::
name|~
name|QKeyMapperPrivate
parameter_list|()
block|{
comment|// clearMappings();
block|}
end_destructor
begin_function
DECL|function|clearMappings
name|void
name|QKeyMapperPrivate
operator|::
name|clearMappings
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|possibleKeys
name|QList
argument_list|<
name|int
argument_list|>
name|QKeyMapperPrivate
operator|::
name|possibleKeys
parameter_list|(
name|QKeyEvent
modifier|*
name|e
parameter_list|)
block|{
name|QList
argument_list|<
name|int
argument_list|>
name|result
decl_stmt|;
if|if
condition|(
name|e
operator|->
name|key
argument_list|()
operator|&&
operator|(
name|e
operator|->
name|key
argument_list|()
operator|!=
name|Qt
operator|::
name|Key_unknown
operator|)
condition|)
name|result
operator|<<
name|int
argument_list|(
name|e
operator|->
name|key
argument_list|()
operator|+
name|e
operator|->
name|modifiers
argument_list|()
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
operator|!
name|e
operator|->
name|text
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|result
operator|<<
name|int
argument_list|(
name|e
operator|->
name|text
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|unicode
argument_list|()
operator|+
name|e
operator|->
name|modifiers
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
