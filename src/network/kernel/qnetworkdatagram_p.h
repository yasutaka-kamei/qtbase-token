begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 Intel Corporation. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNETWORKDATAGRAM_P_H
end_ifndef
begin_define
DECL|macro|QNETWORKDATAGRAM_P_H
define|#
directive|define
name|QNETWORKDATAGRAM_P_H
end_define
begin_include
include|#
directive|include
file|<QtNetwork/qhostaddress.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QIpPacketHeader
block|{
name|public
label|:
name|QIpPacketHeader
argument_list|(
argument|const QHostAddress&dstAddr = QHostAddress()
argument_list|,
argument|quint16 port =
literal|0
argument_list|)
block|:
name|destinationAddress
argument_list|(
name|dstAddr
argument_list|)
operator|,
name|ifindex
argument_list|(
literal|0
argument_list|)
operator|,
name|hopLimit
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|destinationPort
argument_list|(
argument|port
argument_list|)
block|{}
name|void
name|clear
argument_list|()
block|{
name|senderAddress
operator|.
name|clear
argument_list|()
block|;
name|destinationAddress
operator|.
name|clear
argument_list|()
block|;
name|ifindex
operator|=
literal|0
block|;
name|hopLimit
operator|=
operator|-
literal|1
block|;     }
name|QHostAddress
name|senderAddress
expr_stmt|;
name|QHostAddress
name|destinationAddress
decl_stmt|;
name|uint
name|ifindex
decl_stmt|;
name|int
name|hopLimit
decl_stmt|;
name|quint16
name|senderPort
decl_stmt|;
name|quint16
name|destinationPort
decl_stmt|;
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
comment|// QNETWORKDATAGRAM_P_H
end_comment
end_unit