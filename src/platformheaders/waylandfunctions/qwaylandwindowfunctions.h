begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 LG Electronics Ltd, author: mikko.levonmaa@lge.com ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWAYLANDWINDOWFUNCTIONS_H
end_ifndef
begin_define
DECL|macro|QWAYLANDWINDOWFUNCTIONS_H
define|#
directive|define
name|QWAYLANDWINDOWFUNCTIONS_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QByteArray>
end_include
begin_include
include|#
directive|include
file|<QtGui/QGuiApplication>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWindow
name|class
name|QWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWaylandWindowFunctions
block|{
name|public
label|:
typedef|typedef
name|void
function_decl|(
modifier|*
name|SetWindowSync
function_decl|)
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
function_decl|;
typedef|typedef
name|void
function_decl|(
modifier|*
name|SetWindowDeSync
function_decl|)
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
function_decl|;
typedef|typedef
name|bool
function_decl|(
modifier|*
name|IsWindowSync
function_decl|)
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
function_decl|;
specifier|static
specifier|const
name|QByteArray
name|setSyncIdentifier
parameter_list|()
block|{
return|return
name|QByteArrayLiteral
argument_list|(
literal|"WaylandSubSurfaceSetSync"
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|QByteArray
name|setDeSyncIdentifier
parameter_list|()
block|{
return|return
name|QByteArrayLiteral
argument_list|(
literal|"WaylandSubSurfaceSetDeSync"
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|QByteArray
name|isSyncIdentifier
parameter_list|()
block|{
return|return
name|QByteArrayLiteral
argument_list|(
literal|"WaylandSubSurfaceIsSync"
argument_list|)
return|;
block|}
specifier|static
name|void
name|setSync
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
specifier|static
name|SetWindowSync
name|func
init|=
name|reinterpret_cast
operator|<
name|SetWindowSync
operator|>
operator|(
name|QGuiApplication
operator|::
name|platformFunction
argument_list|(
name|setSyncIdentifier
argument_list|()
argument_list|)
operator|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|func
argument_list|)
expr_stmt|;
name|func
argument_list|(
name|window
argument_list|)
expr_stmt|;
block|}
specifier|static
name|void
name|setDeSync
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
specifier|static
name|SetWindowDeSync
name|func
init|=
name|reinterpret_cast
operator|<
name|SetWindowDeSync
operator|>
operator|(
name|QGuiApplication
operator|::
name|platformFunction
argument_list|(
name|setDeSyncIdentifier
argument_list|()
argument_list|)
operator|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|func
argument_list|)
expr_stmt|;
name|func
argument_list|(
name|window
argument_list|)
expr_stmt|;
block|}
specifier|static
name|bool
name|isSync
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
specifier|static
name|IsWindowSync
name|func
init|=
name|reinterpret_cast
operator|<
name|IsWindowSync
operator|>
operator|(
name|QGuiApplication
operator|::
name|platformFunction
argument_list|(
name|isSyncIdentifier
argument_list|()
argument_list|)
operator|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|func
argument_list|)
expr_stmt|;
return|return
name|func
argument_list|(
name|window
argument_list|)
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWAYLANDWINDOWFUNCTIONS_H
end_comment
end_unit
