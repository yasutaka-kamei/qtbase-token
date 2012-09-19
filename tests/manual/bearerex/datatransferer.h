begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|DATATRANSFERER_H
end_ifndef
begin_define
DECL|macro|DATATRANSFERER_H
define|#
directive|define
name|DATATRANSFERER_H
end_define
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QString>
end_include
begin_include
include|#
directive|include
file|<QNetworkReply>
end_include
begin_include
include|#
directive|include
file|<QNetworkAccessManager>
end_include
begin_include
include|#
directive|include
file|<QTcpSocket>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_comment
comment|// Interface-class for data transferring object
end_comment
begin_decl_stmt
name|class
name|DataTransferer
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|DataTransferer
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|DataTransferer
argument_list|()
block|{
if|if
condition|(
name|m_dataTransferOngoing
condition|)
block|{
name|qDebug
argument_list|(
literal|"BearerEx Warning: dataobjects transfer was ongoing when destroyed."
argument_list|)
expr_stmt|;
block|}
block|}
name|virtual
name|bool
name|transferData
argument_list|()
operator|=
literal|0
block|;
name|bool
name|dataTransferOngoing
argument_list|()
block|;
name|signals
operator|:
name|void
name|finished
argument_list|(
argument|quint32 errorCode
argument_list|,
argument|qint64 dataReceived
argument_list|,
argument|QString errorType
argument_list|)
block|;
name|public
name|slots
operator|:
name|protected
operator|:
name|bool
name|m_dataTransferOngoing
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Specializations/concrete classes
end_comment
begin_decl_stmt
name|class
name|DataTransfererQTcp
range|:
name|public
name|DataTransferer
block|{
name|Q_OBJECT
name|public
operator|:
name|DataTransfererQTcp
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|DataTransfererQTcp
argument_list|()
block|;
name|virtual
name|bool
name|transferData
argument_list|()
block|;
name|public
name|slots
operator|:
name|void
name|readyRead
argument_list|()
block|;
name|void
name|error
argument_list|(
argument|QAbstractSocket::SocketError socketError
argument_list|)
block|;
name|void
name|connected
argument_list|()
block|;
name|private
operator|:
name|QTcpSocket
name|m_qsocket
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|DataTransfererQNam
range|:
name|public
name|DataTransferer
block|{
name|Q_OBJECT
name|public
operator|:
name|DataTransfererQNam
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|DataTransfererQNam
argument_list|()
block|;
name|virtual
name|bool
name|transferData
argument_list|()
block|;
name|public
name|slots
operator|:
name|void
name|replyFinished
argument_list|(
name|QNetworkReply
operator|*
name|reply
argument_list|)
block|;
name|private
operator|:
name|QNetworkAccessManager
name|m_qnam
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// DATATRANSFERER_H
end_comment
end_unit
