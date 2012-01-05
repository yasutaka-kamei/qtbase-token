begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QBUFFER_H
end_ifndef
begin_define
DECL|macro|QBUFFER_H
define|#
directive|define
name|QBUFFER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qiodevice.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qbytearray.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Core
argument_list|)
name|class
name|QObject
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QBufferPrivate
name|class
name|QBufferPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QBuffer
range|:
name|public
name|QIODevice
block|{
ifndef|#
directive|ifndef
name|QT_NO_QOBJECT
name|Q_OBJECT
endif|#
directive|endif
name|public
operator|:
ifndef|#
directive|ifndef
name|QT_NO_QOBJECT
name|explicit
name|QBuffer
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QBuffer
argument_list|(
name|QByteArray
operator|*
name|buf
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
else|#
directive|else
name|QBuffer
argument_list|()
block|;
name|explicit
name|QBuffer
argument_list|(
name|QByteArray
operator|*
name|buf
argument_list|)
block|;
endif|#
directive|endif
operator|~
name|QBuffer
argument_list|()
block|;
name|QByteArray
operator|&
name|buffer
argument_list|()
block|;
specifier|const
name|QByteArray
operator|&
name|buffer
argument_list|()
specifier|const
block|;
name|void
name|setBuffer
argument_list|(
name|QByteArray
operator|*
name|a
argument_list|)
block|;
name|void
name|setData
argument_list|(
specifier|const
name|QByteArray
operator|&
name|data
argument_list|)
block|;
specifier|inline
name|void
name|setData
argument_list|(
argument|const char *data
argument_list|,
argument|int len
argument_list|)
block|;
specifier|const
name|QByteArray
operator|&
name|data
argument_list|()
specifier|const
block|;
name|bool
name|open
argument_list|(
argument|OpenMode openMode
argument_list|)
block|;
name|void
name|close
argument_list|()
block|;
name|qint64
name|size
argument_list|()
specifier|const
block|;
name|qint64
name|pos
argument_list|()
specifier|const
block|;
name|bool
name|seek
argument_list|(
argument|qint64 off
argument_list|)
block|;
name|bool
name|atEnd
argument_list|()
specifier|const
block|;
name|bool
name|canReadLine
argument_list|()
specifier|const
block|;
name|protected
operator|:
ifndef|#
directive|ifndef
name|QT_NO_QOBJECT
name|void
name|connectNotify
argument_list|(
specifier|const
name|char
operator|*
argument_list|)
block|;
name|void
name|disconnectNotify
argument_list|(
specifier|const
name|char
operator|*
argument_list|)
block|;
endif|#
directive|endif
name|qint64
name|readData
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxlen
argument_list|)
block|;
name|qint64
name|writeData
argument_list|(
argument|const char *data
argument_list|,
argument|qint64 len
argument_list|)
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QBuffer
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QBuffer
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_emitSignals()
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|setData
specifier|inline
name|void
name|QBuffer
operator|::
name|setData
argument_list|(
argument|const char *adata
argument_list|,
argument|int alen
argument_list|)
block|{
name|setData
argument_list|(
name|QByteArray
argument_list|(
name|adata
argument_list|,
name|alen
argument_list|)
argument_list|)
block|; }
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QBUFFER_H
end_comment
end_unit
