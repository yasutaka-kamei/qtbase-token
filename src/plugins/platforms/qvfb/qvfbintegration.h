begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGRAPHICSSYSTEM_QVFB_H
end_ifndef
begin_define
DECL|macro|QGRAPHICSSYSTEM_QVFB_H
define|#
directive|define
name|QGRAPHICSSYSTEM_QVFB_H
end_define
begin_include
include|#
directive|include
file|<QPlatformScreen>
end_include
begin_include
include|#
directive|include
file|<QPlatformIntegration>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QVFbScreenPrivate
name|class
name|QVFbScreenPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractEventDispatcher
name|class
name|QAbstractEventDispatcher
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QVFbScreen
range|:
name|public
name|QPlatformScreen
block|{
name|public
operator|:
name|QVFbScreen
argument_list|(
argument|int id
argument_list|)
block|;
operator|~
name|QVFbScreen
argument_list|()
block|;
name|QRect
name|geometry
argument_list|()
specifier|const
block|;
name|int
name|depth
argument_list|()
specifier|const
block|;
name|QImage
operator|::
name|Format
name|format
argument_list|()
specifier|const
block|;
name|QSizeF
name|physicalSize
argument_list|()
specifier|const
block|;
name|QImage
operator|*
name|screenImage
argument_list|()
block|;
name|void
name|setDirty
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
block|;
name|public
operator|:
name|QVFbScreenPrivate
operator|*
name|d_ptr
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVFbIntegrationPrivate
name|class
name|QVFbIntegrationPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QVFbIntegration
range|:
name|public
name|QPlatformIntegration
block|{
name|public
operator|:
name|QVFbIntegration
argument_list|(
specifier|const
name|QStringList
operator|&
name|paramList
argument_list|)
block|;
name|QPlatformPixmap
operator|*
name|createPlatformPixmap
argument_list|(
argument|QPlatformPixmap::PixelType type
argument_list|)
specifier|const
block|;
name|QPlatformWindow
operator|*
name|createPlatformWindow
argument_list|(
argument|QWidget *widget
argument_list|,
argument|WId winId
argument_list|)
specifier|const
block|;
name|QWindowSurface
operator|*
name|createWindowSurface
argument_list|(
argument|QWidget *widget
argument_list|,
argument|WId winId
argument_list|)
specifier|const
block|;
name|QAbstractEventDispatcher
operator|*
name|createEventDispatcher
argument_list|()
specifier|const
block|;
name|QList
operator|<
name|QPlatformScreen
operator|*
operator|>
name|screens
argument_list|()
specifier|const
block|{
return|return
name|mScreens
return|;
block|}
name|QPlatformFontDatabase
operator|*
name|fontDatabase
argument_list|()
specifier|const
block|;
name|private
operator|:
name|QVFbScreen
operator|*
name|mPrimaryScreen
block|;
name|QList
operator|<
name|QPlatformScreen
operator|*
operator|>
name|mScreens
block|;
name|QPlatformFontDatabase
operator|*
name|mFontDb
block|; }
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
