begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2013 Klaralvdalens Datakonsult AB (KDAB) ** Contact: http://www.qt-project.org/legal ** ** This file is part of the utilities of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LEGACYSPECPARSER_H
end_ifndef
begin_define
DECL|macro|LEGACYSPECPARSER_H
define|#
directive|define
name|LEGACYSPECPARSER_H
end_define
begin_include
include|#
directive|include
file|"specparser.h"
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<QVariant>
end_include
begin_decl_stmt
DECL|variable|QTextStream
name|class
name|QTextStream
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|LegacySpecParser
range|:
name|public
name|SpecParser
block|{
name|public
operator|:
name|virtual
name|QList
operator|<
name|Version
operator|>
name|versions
argument_list|()
specifier|const
block|{
return|return
name|m_versions
return|;
block|}
name|virtual
name|bool
name|parse
argument_list|()
block|;
name|protected
operator|:
specifier|const
name|QMultiHash
operator|<
name|VersionProfile
block|,
name|Function
operator|>
operator|&
name|versionFunctions
argument_list|()
specifier|const
block|{
return|return
name|m_functions
return|;
block|}
specifier|const
name|QMultiMap
operator|<
name|QString
block|,
name|FunctionProfile
operator|>
operator|&
name|extensionFunctions
argument_list|()
specifier|const
block|{
return|return
name|m_extensionFunctions
return|;
block|}
name|private
operator|:
name|QMap
operator|<
name|QString
block|,
name|QString
operator|>
name|m_typeMap
block|;
name|QMultiHash
operator|<
name|VersionProfile
block|,
name|Function
operator|>
name|m_functions
block|;
name|QList
operator|<
name|Version
operator|>
name|m_versions
block|;
comment|// Extension support
name|QMultiMap
operator|<
name|QString
block|,
name|FunctionProfile
operator|>
name|m_extensionFunctions
block|;
name|bool
name|parseTypeMap
argument_list|()
block|;
name|void
name|parseEnums
argument_list|()
block|;
name|void
name|parseFunctions
argument_list|(
name|QTextStream
operator|&
name|stream
argument_list|)
block|;
name|bool
name|inDeprecationException
argument_list|(
argument|const QString&functionName
argument_list|)
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LEGACYSPECPARSER_H
end_comment
end_unit