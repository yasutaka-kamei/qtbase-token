begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdirectfbintegration.h"
end_include
begin_include
include|#
directive|include
file|"qdirectfbbackingstore.h"
end_include
begin_include
include|#
directive|include
file|"qdirectfbblitter.h"
end_include
begin_include
include|#
directive|include
file|"qdirectfbconvenience.h"
end_include
begin_include
include|#
directive|include
file|"qdirectfbcursor.h"
end_include
begin_include
include|#
directive|include
file|"qdirectfbwindow.h"
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qgenericunixfontdatabase_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qgenericunixeventdispatcher_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qpixmap_blitter_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qpixmap_raster_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformpixmap.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtCore/QThread>
end_include
begin_include
include|#
directive|include
file|<QtCore/QAbstractEventDispatcher>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QDirectFbIntegration
name|QDirectFbIntegration
operator|::
name|QDirectFbIntegration
parameter_list|()
member_init_list|:
name|m_fontDb
argument_list|(
operator|new
name|QGenericUnixFontDatabase
argument_list|()
argument_list|)
member_init_list|,
name|m_eventDispatcher
argument_list|(
name|createUnixEventDispatcher
argument_list|()
argument_list|)
block|{
name|QGuiApplicationPrivate
operator|::
name|instance
argument_list|()
operator|->
name|setEventDispatcher
argument_list|(
name|m_eventDispatcher
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|initialize
name|void
name|QDirectFbIntegration
operator|::
name|initialize
parameter_list|()
block|{
name|initializeDirectFB
argument_list|()
expr_stmt|;
name|initializeScreen
argument_list|()
expr_stmt|;
name|initializeInput
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|initializeDirectFB
name|void
name|QDirectFbIntegration
operator|::
name|initializeDirectFB
parameter_list|()
block|{
specifier|const
name|QStringList
name|args
init|=
name|QCoreApplication
operator|::
name|arguments
argument_list|()
decl_stmt|;
name|int
name|argc
init|=
name|args
operator|.
name|size
argument_list|()
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
init|=
operator|new
name|char
operator|*
index|[
name|argc
index|]
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|argc
condition|;
operator|++
name|i
control|)
name|argv
index|[
name|i
index|]
operator|=
name|qstrdup
argument_list|(
name|args
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|toLocal8Bit
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|DFBResult
name|result
init|=
name|DirectFBInit
argument_list|(
operator|&
name|argc
argument_list|,
operator|&
name|argv
argument_list|)
decl_stmt|;
if|if
condition|(
name|result
operator|!=
name|DFB_OK
condition|)
block|{
name|DirectFBError
argument_list|(
literal|"QDirectFBScreen: error initializing DirectFB"
argument_list|,
name|result
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|argc
condition|;
operator|++
name|i
control|)
operator|delete
index|[]
name|argv
index|[
name|i
index|]
expr_stmt|;
operator|delete
index|[]
name|argv
expr_stmt|;
comment|// This must happen after DirectFBInit.
name|m_dfb
operator|.
name|reset
argument_list|(
name|QDirectFbConvenience
operator|::
name|dfbInterface
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|initializeScreen
name|void
name|QDirectFbIntegration
operator|::
name|initializeScreen
parameter_list|()
block|{
name|m_primaryScreen
operator|.
name|reset
argument_list|(
operator|new
name|QDirectFbScreen
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|screenAdded
argument_list|(
name|m_primaryScreen
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|initializeInput
name|void
name|QDirectFbIntegration
operator|::
name|initializeInput
parameter_list|()
block|{
name|m_input
operator|.
name|reset
argument_list|(
operator|new
name|QDirectFbInput
argument_list|(
name|m_dfb
operator|.
name|data
argument_list|()
argument_list|,
name|m_primaryScreen
operator|->
name|dfbLayer
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|m_input
operator|->
name|start
argument_list|()
expr_stmt|;
block|}
end_function
begin_destructor
DECL|function|~QDirectFbIntegration
name|QDirectFbIntegration
operator|::
name|~
name|QDirectFbIntegration
parameter_list|()
block|{
name|m_input
operator|->
name|stopInputEventLoop
argument_list|()
expr_stmt|;
name|m_input
operator|->
name|wait
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|createPlatformPixmap
name|QPlatformPixmap
modifier|*
name|QDirectFbIntegration
operator|::
name|createPlatformPixmap
parameter_list|(
name|QPlatformPixmap
operator|::
name|PixelType
name|type
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|type
operator|==
name|QPlatformPixmap
operator|::
name|BitmapType
condition|)
return|return
operator|new
name|QRasterPlatformPixmap
argument_list|(
name|type
argument_list|)
return|;
else|else
return|return
operator|new
name|QDirectFbBlitterPlatformPixmap
return|;
block|}
end_function
begin_function
DECL|function|createPlatformWindow
name|QPlatformWindow
modifier|*
name|QDirectFbIntegration
operator|::
name|createPlatformWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
name|QDirectFbWindow
modifier|*
name|dfbWindow
init|=
operator|new
name|QDirectFbWindow
argument_list|(
name|window
argument_list|,
name|m_input
operator|.
name|data
argument_list|()
argument_list|)
decl_stmt|;
name|dfbWindow
operator|->
name|createDirectFBWindow
argument_list|()
expr_stmt|;
return|return
name|dfbWindow
return|;
block|}
end_function
begin_function
DECL|function|guiThreadEventDispatcher
name|QAbstractEventDispatcher
modifier|*
name|QDirectFbIntegration
operator|::
name|guiThreadEventDispatcher
parameter_list|()
specifier|const
block|{
return|return
name|m_eventDispatcher
return|;
block|}
end_function
begin_function
DECL|function|createPlatformBackingStore
name|QPlatformBackingStore
modifier|*
name|QDirectFbIntegration
operator|::
name|createPlatformBackingStore
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QDirectFbBackingStore
argument_list|(
name|window
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|fontDatabase
name|QPlatformFontDatabase
modifier|*
name|QDirectFbIntegration
operator|::
name|fontDatabase
parameter_list|()
specifier|const
block|{
return|return
name|m_fontDb
operator|.
name|data
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
