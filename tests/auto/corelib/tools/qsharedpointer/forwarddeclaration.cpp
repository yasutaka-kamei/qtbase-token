begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_define
DECL|macro|QT_SHAREDPOINTER_TRACK_POINTERS
define|#
directive|define
name|QT_SHAREDPOINTER_TRACK_POINTERS
end_define
begin_include
include|#
directive|include
file|"qsharedpointer.h"
end_include
begin_class_decl
class_decl|class
name|ForwardDeclared
class_decl|;
end_class_decl
begin_function_decl
name|ForwardDeclared
modifier|*
name|forwardPointer
parameter_list|()
function_decl|;
end_function_decl
begin_function
DECL|function|externalForwardDeclaration
name|void
name|externalForwardDeclaration
parameter_list|()
block|{
struct|struct
name|Wrapper
block|{
name|QSharedPointer
argument_list|<
name|ForwardDeclared
argument_list|>
name|pointer
decl_stmt|;
block|}
struct|;
block|}
end_function
end_unit
