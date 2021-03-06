begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 KlarÃ¤lvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author Volker Krause<volker.krause@kdab.com> ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QHOOKS_H
end_ifndef
begin_define
DECL|macro|QHOOKS_H
define|#
directive|define
name|QHOOKS_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QObject
name|class
name|QObject
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|namespace
name|QHooks
block|{
enum|enum
name|HookIndex
block|{
name|HookDataVersion
init|=
literal|0
block|,
name|HookDataSize
init|=
literal|1
block|,
name|QtVersion
init|=
literal|2
block|,
name|AddQObject
init|=
literal|3
block|,
name|RemoveQObject
init|=
literal|4
block|,
name|Startup
init|=
literal|5
block|,
name|TypeInformationVersion
init|=
literal|6
block|,
name|LastHookIndex
block|}
enum|;
typedef|typedef
name|void
function_decl|(
modifier|*
name|AddQObjectCallback
function_decl|)
parameter_list|(
name|QObject
modifier|*
parameter_list|)
function_decl|;
typedef|typedef
name|void
function_decl|(
modifier|*
name|RemoveQObjectCallback
function_decl|)
parameter_list|(
name|QObject
modifier|*
parameter_list|)
function_decl|;
typedef|typedef
name|void
function_decl|(
modifier|*
name|StartupCallback
function_decl|)
parameter_list|()
function_decl|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|extern
name|quintptr
name|Q_CORE_EXPORT
name|qtHookData
index|[]
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
