begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QICUCODEC_P_H
end_ifndef
begin_define
DECL|macro|QICUCODEC_P_H
define|#
directive|define
name|QICUCODEC_P_H
end_define
begin_include
include|#
directive|include
file|"QtCore/qtextcodec.h"
end_include
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
begin_extern
extern|extern
literal|"C"
block|{
DECL|typedef|UConverter
typedef|typedef
name|struct
name|UConverter
name|UConverter
typedef|;
block|}
end_extern
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_TEXTCODEC
name|class
name|QIcuCodec
range|:
name|public
name|QTextCodec
block|{
name|public
operator|:
specifier|static
name|QList
operator|<
name|QByteArray
operator|>
name|availableCodecs
argument_list|()
block|;
specifier|static
name|QList
operator|<
name|int
operator|>
name|availableMibs
argument_list|()
block|;
specifier|static
name|QTextCodec
operator|*
name|defaultCodecUnlocked
argument_list|()
block|;
specifier|static
name|QTextCodec
operator|*
name|codecForNameUnlocked
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|)
block|;
specifier|static
name|QTextCodec
operator|*
name|codecForMibUnlocked
argument_list|(
argument|int mib
argument_list|)
block|;
name|QString
name|convertToUnicode
argument_list|(
argument|const char *
argument_list|,
argument|int
argument_list|,
argument|ConverterState *
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QByteArray
name|convertFromUnicode
argument_list|(
argument|const QChar *
argument_list|,
argument|int
argument_list|,
argument|ConverterState *
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QByteArray
name|name
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QList
operator|<
name|QByteArray
operator|>
name|aliases
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|mibEnum
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|QIcuCodec
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|)
block|;
operator|~
name|QIcuCodec
argument_list|()
block|;
name|UConverter
operator|*
name|getConverter
argument_list|(
argument|QTextCodec::ConverterState *state
argument_list|)
specifier|const
block|;
specifier|const
name|char
operator|*
name|m_name
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TEXTCODEC
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
