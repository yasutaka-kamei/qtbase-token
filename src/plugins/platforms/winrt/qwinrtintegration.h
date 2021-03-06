begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINRTINTEGRATION_H
end_ifndef
begin_define
DECL|macro|QWINRTINTEGRATION_H
define|#
directive|define
name|QWINRTINTEGRATION_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformintegration.h>
end_include
begin_decl_stmt
name|namespace
name|ABI
block|{
name|namespace
name|Windows
block|{
name|namespace
name|ApplicationModel
block|{
struct_decl|struct
name|ISuspendingEventArgs
struct_decl|;
block|}
name|namespace
name|Foundation
block|{
struct_decl|struct
name|IAsyncAction
struct_decl|;
block|}
if|#
directive|if
name|WINAPI_FAMILY_PARTITION
argument_list|(
name|WINAPI_PARTITION_PHONE_APP
argument_list|)
name|namespace
name|Phone
block|{
name|namespace
name|UI
block|{
name|namespace
name|Input
block|{
struct_decl|struct
name|IBackPressedEventArgs
struct_decl|;
struct_decl|struct
name|ICameraEventArgs
struct_decl|;
block|}
block|}
block|}
endif|#
directive|endif
block|}
block|}
end_decl_stmt
begin_struct_decl
struct_decl|struct
name|IAsyncInfo
struct_decl|;
end_struct_decl
begin_struct_decl
struct_decl|struct
name|IInspectable
struct_decl|;
end_struct_decl
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QAbstractEventDispatcher
name|class
name|QAbstractEventDispatcher
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWinRTIntegrationPrivate
name|class
name|QWinRTIntegrationPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWinRTIntegration
range|:
name|public
name|QPlatformIntegration
block|{
name|private
operator|:
name|explicit
name|QWinRTIntegration
argument_list|()
block|;
name|public
operator|:
operator|~
name|QWinRTIntegration
argument_list|()
block|;
specifier|static
name|QWinRTIntegration
operator|*
name|create
argument_list|()
block|{
name|QScopedPointer
operator|<
name|QWinRTIntegration
operator|>
name|integration
argument_list|(
argument|new QWinRTIntegration
argument_list|)
block|;
return|return
name|integration
operator|->
name|succeeded
argument_list|()
condition|?
name|integration
operator|.
name|take
argument_list|()
else|:
name|nullptr
return|;
block|}
name|bool
name|succeeded
argument_list|()
specifier|const
block|;
name|bool
name|hasCapability
argument_list|(
argument|QPlatformIntegration::Capability cap
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QVariant
name|styleHint
argument_list|(
argument|StyleHint hint
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QPlatformWindow
operator|*
name|createPlatformWindow
argument_list|(
argument|QWindow *window
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QPlatformBackingStore
operator|*
name|createPlatformBackingStore
argument_list|(
argument|QWindow *window
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QPlatformOpenGLContext
operator|*
name|createPlatformOpenGLContext
argument_list|(
argument|QOpenGLContext *context
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QAbstractEventDispatcher
operator|*
name|createEventDispatcher
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|initialize
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|QPlatformFontDatabase
operator|*
name|fontDatabase
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QPlatformInputContext
operator|*
name|inputContext
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QPlatformServices
operator|*
name|services
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QPlatformClipboard
operator|*
name|clipboard
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
name|QPlatformDrag
operator|*
name|drag
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
endif|#
directive|endif
name|Qt
operator|::
name|KeyboardModifiers
name|queryKeyboardModifiers
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QStringList
name|themeNames
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QPlatformTheme
operator|*
name|createPlatformTheme
argument_list|(
argument|const QString&name
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QPlatformOffscreenSurface
operator|*
name|createPlatformOffscreenSurface
argument_list|(
argument|QOffscreenSurface *surface
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
if|#
directive|if
name|WINAPI_FAMILY_PARTITION
argument_list|(
name|WINAPI_PARTITION_PHONE_APP
argument_list|)
name|HRESULT
name|onBackButtonPressed
argument_list|(
name|IInspectable
operator|*
argument_list|,
name|ABI
operator|::
name|Windows
operator|::
name|Phone
operator|::
name|UI
operator|::
name|Input
operator|::
name|IBackPressedEventArgs
operator|*
name|args
argument_list|)
block|;
name|HRESULT
name|onCameraPressed
argument_list|(
name|IInspectable
operator|*
argument_list|,
name|ABI
operator|::
name|Windows
operator|::
name|Phone
operator|::
name|UI
operator|::
name|Input
operator|::
name|ICameraEventArgs
operator|*
argument_list|)
block|;
name|HRESULT
name|onCameraHalfPressed
argument_list|(
name|IInspectable
operator|*
argument_list|,
name|ABI
operator|::
name|Windows
operator|::
name|Phone
operator|::
name|UI
operator|::
name|Input
operator|::
name|ICameraEventArgs
operator|*
argument_list|)
block|;
name|HRESULT
name|onCameraReleased
argument_list|(
name|IInspectable
operator|*
argument_list|,
name|ABI
operator|::
name|Windows
operator|::
name|Phone
operator|::
name|UI
operator|::
name|Input
operator|::
name|ICameraEventArgs
operator|*
argument_list|)
block|;
endif|#
directive|endif
name|HRESULT
name|onSuspended
argument_list|(
name|IInspectable
operator|*
argument_list|,
name|ABI
operator|::
name|Windows
operator|::
name|ApplicationModel
operator|::
name|ISuspendingEventArgs
operator|*
argument_list|)
block|;
name|HRESULT
name|onResume
argument_list|(
name|IInspectable
operator|*
argument_list|,
name|IInspectable
operator|*
argument_list|)
block|;
name|QScopedPointer
operator|<
name|QWinRTIntegrationPrivate
operator|>
name|d_ptr
block|;
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QWinRTIntegration
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINRTINTEGRATION_H
end_comment
end_unit
