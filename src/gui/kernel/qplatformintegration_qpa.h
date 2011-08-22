begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLATFORMINTEGRATION_H
end_ifndef
begin_define
DECL|macro|QPLATFORMINTEGRATION_H
define|#
directive|define
name|QPLATFORMINTEGRATION_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qwindowdefs.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qplatformscreen_qpa.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qsurfaceformat.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
parameter_list|(
name|Gui
parameter_list|)
name|class
name|QPlatformWindow
decl_stmt|;
DECL|variable|QWindow
name|class
name|QWindow
decl_stmt|;
DECL|variable|QPlatformBackingStore
name|class
name|QPlatformBackingStore
decl_stmt|;
DECL|variable|QPlatformFontDatabase
name|class
name|QPlatformFontDatabase
decl_stmt|;
DECL|variable|QPlatformClipboard
name|class
name|QPlatformClipboard
decl_stmt|;
DECL|variable|QPlatformNativeInterface
name|class
name|QPlatformNativeInterface
decl_stmt|;
DECL|variable|QPlatformDrag
name|class
name|QPlatformDrag
decl_stmt|;
DECL|variable|QPlatformOpenGLContext
name|class
name|QPlatformOpenGLContext
decl_stmt|;
DECL|variable|QGuiGLFormat
name|class
name|QGuiGLFormat
decl_stmt|;
DECL|variable|QAbstractEventDispatcher
name|class
name|QAbstractEventDispatcher
decl_stmt|;
DECL|variable|QPlatformInputContext
name|class
name|QPlatformInputContext
decl_stmt|;
name|class
name|Q_GUI_EXPORT
name|QPlatformIntegration
decl_stmt|{ public:     enum Capability
block|{
name|ThreadedPixmaps
operator|=
literal|1
operator|,
name|OpenGL
operator|=
literal|2
operator|,
name|ThreadedOpenGL
operator|=
literal|3
block|}
end_function
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|virtual
operator|~
name|QPlatformIntegration
argument_list|()
block|{ }
name|virtual
name|bool
name|hasCapability
argument_list|(
argument|Capability cap
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|virtual
name|QPlatformPixmap
modifier|*
name|createPlatformPixmap
argument_list|(
name|QPlatformPixmap
operator|::
name|PixelType
name|type
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|virtual
name|QPlatformWindow
modifier|*
name|createPlatformWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|virtual
name|QPlatformBackingStore
modifier|*
name|createPlatformBackingStore
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|virtual
name|QPlatformOpenGLContext
modifier|*
name|createPlatformOpenGLContext
argument_list|(
name|QOpenGLContext
operator|*
name|context
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Event dispatcher:
end_comment
begin_expr_stmt
name|virtual
name|QAbstractEventDispatcher
operator|*
name|guiThreadEventDispatcher
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
end_expr_stmt
begin_comment
comment|//Deeper window system integrations
end_comment
begin_expr_stmt
name|virtual
name|QPlatformFontDatabase
operator|*
name|fontDatabase
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
end_ifndef
begin_expr_stmt
name|virtual
name|QPlatformClipboard
operator|*
name|clipboard
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
end_ifndef
begin_expr_stmt
name|virtual
name|QPlatformDrag
operator|*
name|drag
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|virtual
name|QPlatformInputContext
operator|*
name|inputContext
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Access native handles. The window handle is already available from Wid;
end_comment
begin_expr_stmt
name|virtual
name|QPlatformNativeInterface
operator|*
name|nativeInterface
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_label
name|protected
label|:
end_label
begin_function_decl
name|void
name|screenAdded
parameter_list|(
name|QPlatformScreen
modifier|*
name|screen
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
unit|};
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPLATFORMINTEGRATION_H
end_comment
end_unit
