begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLATFORMINTEGRATION_COCOA_H
end_ifndef
begin_define
DECL|macro|QPLATFORMINTEGRATION_COCOA_H
define|#
directive|define
name|QPLATFORMINTEGRATION_COCOA_H
end_define
begin_include
include|#
directive|include
file|<AppKit/AppKit.h>
end_include
begin_include
include|#
directive|include
file|"qcocoacursor.h"
end_include
begin_include
include|#
directive|include
file|"qcocoawindow.h"
end_include
begin_include
include|#
directive|include
file|"qcocoanativeinterface.h"
end_include
begin_include
include|#
directive|include
file|"qcocoainputcontext.h"
end_include
begin_include
include|#
directive|include
file|"qcocoaaccessibility.h"
end_include
begin_include
include|#
directive|include
file|"qcocoaclipboard.h"
end_include
begin_include
include|#
directive|include
file|"qcocoadrag.h"
end_include
begin_include
include|#
directive|include
file|"qcocoaservices.h"
end_include
begin_include
include|#
directive|include
file|"qcocoakeymapper.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QScopedPointer>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformintegration.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qcoretextfontdatabase_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QCocoaScreen
range|:
name|public
name|QPlatformScreen
block|{
name|public
operator|:
name|QCocoaScreen
argument_list|(
argument|int screenIndex
argument_list|)
block|;
operator|~
name|QCocoaScreen
argument_list|()
block|;
comment|// ----------------------------------------------------
comment|// Virtual methods overridden from QPlatformScreen
name|QPixmap
name|grabWindow
argument_list|(
argument|WId window
argument_list|,
argument|int x
argument_list|,
argument|int y
argument_list|,
argument|int width
argument_list|,
argument|int height
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QRect
name|geometry
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|m_geometry
return|;
block|}
name|QRect
name|availableGeometry
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|m_availableGeometry
return|;
block|}
name|int
name|depth
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|m_depth
return|;
block|}
name|QImage
operator|::
name|Format
name|format
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|m_format
return|;
block|}
name|qreal
name|devicePixelRatio
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QSizeF
name|physicalSize
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|m_physicalSize
return|;
block|}
name|QDpi
name|logicalDpi
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|m_logicalDpi
return|;
block|}
name|qreal
name|refreshRate
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|m_refreshRate
return|;
block|}
name|QString
name|name
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|m_name
return|;
block|}
name|QPlatformCursor
operator|*
name|cursor
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|m_cursor
return|;
block|}
name|QWindow
operator|*
name|topLevelAt
argument_list|(
argument|const QPoint&point
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QList
operator|<
name|QPlatformScreen
operator|*
operator|>
name|virtualSiblings
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|m_siblings
return|;
block|}
name|QPlatformScreen
operator|::
name|SubpixelAntialiasingType
name|subpixelAntialiasingTypeHint
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
comment|// ----------------------------------------------------
comment|// Additional methods
name|void
name|setVirtualSiblings
argument_list|(
argument|const QList<QPlatformScreen *>&siblings
argument_list|)
block|{
name|m_siblings
operator|=
name|siblings
block|; }
name|NSScreen
operator|*
name|osScreen
argument_list|()
specifier|const
block|;
name|void
name|updateGeometry
argument_list|()
block|;
name|public
operator|:
name|int
name|m_screenIndex
block|;
name|QRect
name|m_geometry
block|;
name|QRect
name|m_availableGeometry
block|;
name|QDpi
name|m_logicalDpi
block|;
name|qreal
name|m_refreshRate
block|;
name|int
name|m_depth
block|;
name|QString
name|m_name
block|;
name|QImage
operator|::
name|Format
name|m_format
block|;
name|QSizeF
name|m_physicalSize
block|;
name|QCocoaCursor
operator|*
name|m_cursor
block|;
name|QList
operator|<
name|QPlatformScreen
operator|*
operator|>
name|m_siblings
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QCocoaIntegration
range|:
name|public
name|QPlatformIntegration
block|{
name|public
operator|:
expr|enum
name|Option
block|{
name|UseFreeTypeFontEngine
operator|=
literal|0x1
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|Options
argument_list|,
argument|Option
argument_list|)
name|QCocoaIntegration
argument_list|(
specifier|const
name|QStringList
operator|&
name|paramList
argument_list|)
block|;
operator|~
name|QCocoaIntegration
argument_list|()
block|;
specifier|static
name|QCocoaIntegration
operator|*
name|instance
argument_list|()
block|;
name|Options
name|options
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
name|QPlatformWindow
operator|*
name|createPlatformWindow
argument_list|(
argument|QWindow *window
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
name|QPlatformOpenGLContext
operator|*
name|createPlatformOpenGLContext
argument_list|(
argument|QOpenGLContext *context
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
endif|#
directive|endif
name|QPlatformBackingStore
operator|*
name|createPlatformBackingStore
argument_list|(
argument|QWindow *widget
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
name|QCoreTextFontDatabase
operator|*
name|fontDatabase
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QCocoaNativeInterface
operator|*
name|nativeInterface
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
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
name|QCocoaAccessibility
operator|*
name|accessibility
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
endif|#
directive|endif
name|QCocoaClipboard
operator|*
name|clipboard
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QCocoaDrag
operator|*
name|drag
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
name|QCocoaServices
operator|*
name|services
argument_list|()
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
name|Qt
operator|::
name|KeyboardModifiers
name|queryKeyboardModifiers
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QList
operator|<
name|int
operator|>
name|possibleKeys
argument_list|(
argument|const QKeyEvent *event
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|updateScreens
argument_list|()
block|;
name|QCocoaScreen
operator|*
name|screenAtIndex
argument_list|(
argument|int index
argument_list|)
block|;
name|void
name|setToolbar
argument_list|(
name|QWindow
operator|*
name|window
argument_list|,
name|NSToolbar
operator|*
name|toolbar
argument_list|)
block|;
name|NSToolbar
operator|*
name|toolbar
argument_list|(
argument|QWindow *window
argument_list|)
specifier|const
block|;
name|void
name|clearToolbars
argument_list|()
block|;
name|void
name|pushPopupWindow
argument_list|(
name|QCocoaWindow
operator|*
name|window
argument_list|)
block|;
name|QCocoaWindow
operator|*
name|popPopupWindow
argument_list|()
block|;
name|QCocoaWindow
operator|*
name|activePopupWindow
argument_list|()
specifier|const
block|;
name|QList
operator|<
name|QCocoaWindow
operator|*
operator|>
operator|*
name|popupWindowStack
argument_list|()
block|;
name|void
name|setApplicationIcon
argument_list|(
argument|const QIcon&icon
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|beep
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
specifier|static
name|QCocoaIntegration
operator|*
name|mInstance
block|;
name|Options
name|mOptions
block|;
name|QScopedPointer
operator|<
name|QCoreTextFontDatabase
operator|>
name|mFontDb
block|;
name|QScopedPointer
operator|<
name|QPlatformInputContext
operator|>
name|mInputContext
block|;
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
name|QScopedPointer
operator|<
name|QCocoaAccessibility
operator|>
name|mAccessibility
block|;
endif|#
directive|endif
name|QScopedPointer
operator|<
name|QPlatformTheme
operator|>
name|mPlatformTheme
block|;
name|QList
operator|<
name|QCocoaScreen
operator|*
operator|>
name|mScreens
block|;
name|QCocoaClipboard
operator|*
name|mCocoaClipboard
block|;
name|QScopedPointer
operator|<
name|QCocoaDrag
operator|>
name|mCocoaDrag
block|;
name|QScopedPointer
operator|<
name|QCocoaNativeInterface
operator|>
name|mNativeInterface
block|;
name|QScopedPointer
operator|<
name|QCocoaServices
operator|>
name|mServices
block|;
name|QScopedPointer
operator|<
name|QCocoaKeyMapper
operator|>
name|mKeyboardMapper
block|;
name|QHash
operator|<
name|QWindow
operator|*
block|,
name|NSToolbar
operator|*
operator|>
name|mToolbars
block|;
name|QList
operator|<
name|QCocoaWindow
operator|*
operator|>
name|m_popupWindowStack
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QCocoaIntegration::Options
argument_list|)
end_macro
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
