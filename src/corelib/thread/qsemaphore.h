begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSEMAPHORE_H
end_ifndef
begin_define
DECL|macro|QSEMAPHORE_H
define|#
directive|define
name|QSEMAPHORE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
parameter_list|(
name|Core
parameter_list|)
ifndef|#
directive|ifndef
name|QT_NO_THREAD
name|class
name|QSemaphorePrivate
decl_stmt|;
name|class
name|Q_CORE_EXPORT
name|QSemaphore
decl_stmt|{ public:     explicit QSemaphore(int n = 0
end_function
begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt
begin_expr_stmt
operator|~
name|QSemaphore
argument_list|()
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|acquire
parameter_list|(
name|int
name|n
init|=
literal|1
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|tryAcquire
parameter_list|(
name|int
name|n
init|=
literal|1
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|tryAcquire
parameter_list|(
name|int
name|n
parameter_list|,
name|int
name|timeout
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|release
parameter_list|(
name|int
name|n
init|=
literal|1
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|int
name|available
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_macro
name|Q_DISABLE_COPY
argument_list|(
argument|QSemaphore
argument_list|)
end_macro
begin_decl_stmt
name|QSemaphorePrivate
modifier|*
name|d
decl_stmt|;
end_decl_stmt
begin_endif
unit|};
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_THREAD
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSEMAPHORE_H
end_comment
end_unit
