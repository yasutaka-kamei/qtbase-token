begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTEXTIMAGEHANDLER_P_H
end_ifndef
begin_define
DECL|macro|QTEXTIMAGEHANDLER_P_H
define|#
directive|define
name|QTEXTIMAGEHANDLER_P_H
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
file|"QtCore/qobject.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qabstracttextdocumentlayout.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QTextImageFormat
name|class
name|QTextImageFormat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QObject
name|class
name|Q_GUI_EXPORT
name|QTextImageHandler
range|:
name|public
name|QObject
decl_stmt|,
name|public
name|QTextObjectInterface
block|{
name|Q_OBJECT
name|Q_INTERFACES
argument_list|(
name|QTextObjectInterface
argument_list|)
name|public
range|:
name|explicit
name|QTextImageHandler
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
decl_stmt|;
name|virtual
name|QSizeF
name|intrinsicSize
parameter_list|(
name|QTextDocument
modifier|*
name|doc
parameter_list|,
name|int
name|posInDocument
parameter_list|,
specifier|const
name|QTextFormat
modifier|&
name|format
parameter_list|)
function_decl|;
name|virtual
name|void
name|drawObject
parameter_list|(
name|QPainter
modifier|*
name|p
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|,
name|QTextDocument
modifier|*
name|doc
parameter_list|,
name|int
name|posInDocument
parameter_list|,
specifier|const
name|QTextFormat
modifier|&
name|format
parameter_list|)
function_decl|;
name|QImage
name|image
parameter_list|(
name|QTextDocument
modifier|*
name|doc
parameter_list|,
specifier|const
name|QTextImageFormat
modifier|&
name|imageFormat
parameter_list|)
function_decl|;
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
comment|// QTEXTIMAGEHANDLER_P_H
end_comment
end_unit
