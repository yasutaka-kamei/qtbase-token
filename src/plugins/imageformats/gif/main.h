begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qimageiohandler.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_IMAGEFORMATPLUGIN
end_ifndef
begin_ifdef
ifdef|#
directive|ifdef
name|QT_NO_IMAGEFORMAT_GIF
end_ifdef
begin_undef
DECL|macro|QT_NO_IMAGEFORMAT_GIF
undef|#
directive|undef
name|QT_NO_IMAGEFORMAT_GIF
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<qgifhandler_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QGifPlugin
range|:
name|public
name|QImageIOPlugin
block|{
name|Q_OBJECT
name|Q_PLUGIN_METADATA
argument_list|(
argument|IID
literal|"org.qt-project.Qt.QImageIOHandlerFactoryInterface"
argument|FILE
literal|"gif.json"
argument_list|)
name|public
operator|:
name|QGifPlugin
argument_list|()
block|;
operator|~
name|QGifPlugin
argument_list|()
block|;
name|Capabilities
name|capabilities
argument_list|(
argument|QIODevice *device
argument_list|,
argument|const QByteArray&format
argument_list|)
specifier|const
block|;
name|QImageIOHandler
operator|*
name|create
argument_list|(
argument|QIODevice *device
argument_list|,
argument|const QByteArray&format = QByteArray()
argument_list|)
specifier|const
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
begin_comment
comment|// QT_NO_IMAGEFORMATPLUGIN
end_comment
end_unit
