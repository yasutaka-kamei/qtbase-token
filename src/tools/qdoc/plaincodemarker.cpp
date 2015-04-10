begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"plaincodemarker.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|PlainCodeMarker
name|PlainCodeMarker
operator|::
name|PlainCodeMarker
parameter_list|()
block|{ }
end_function
begin_destructor
DECL|function|~PlainCodeMarker
name|PlainCodeMarker
operator|::
name|~
name|PlainCodeMarker
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|recognizeCode
name|bool
name|PlainCodeMarker
operator|::
name|recognizeCode
parameter_list|(
specifier|const
name|QString
modifier|&
comment|/* code */
parameter_list|)
block|{
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|recognizeExtension
name|bool
name|PlainCodeMarker
operator|::
name|recognizeExtension
parameter_list|(
specifier|const
name|QString
modifier|&
comment|/* ext */
parameter_list|)
block|{
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|recognizeLanguage
name|bool
name|PlainCodeMarker
operator|::
name|recognizeLanguage
parameter_list|(
specifier|const
name|QString
modifier|&
comment|/* lang */
parameter_list|)
block|{
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|atomType
name|Atom
operator|::
name|AtomType
name|PlainCodeMarker
operator|::
name|atomType
parameter_list|()
specifier|const
block|{
return|return
name|Atom
operator|::
name|Code
return|;
block|}
end_function
begin_function
DECL|function|markedUpCode
name|QString
name|PlainCodeMarker
operator|::
name|markedUpCode
parameter_list|(
specifier|const
name|QString
modifier|&
name|code
parameter_list|,
specifier|const
name|Node
modifier|*
comment|/* relative */
parameter_list|,
specifier|const
name|Location
modifier|&
comment|/* location */
parameter_list|)
block|{
return|return
name|protect
argument_list|(
name|code
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|markedUpSynopsis
name|QString
name|PlainCodeMarker
operator|::
name|markedUpSynopsis
parameter_list|(
specifier|const
name|Node
modifier|*
comment|/* node */
parameter_list|,
specifier|const
name|Node
modifier|*
comment|/* relative */
parameter_list|,
name|SynopsisStyle
comment|/* style */
parameter_list|)
block|{
return|return
literal|"foo"
return|;
block|}
end_function
begin_function
DECL|function|markedUpName
name|QString
name|PlainCodeMarker
operator|::
name|markedUpName
parameter_list|(
specifier|const
name|Node
modifier|*
comment|/* node */
parameter_list|)
block|{
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|markedUpFullName
name|QString
name|PlainCodeMarker
operator|::
name|markedUpFullName
parameter_list|(
specifier|const
name|Node
modifier|*
comment|/* node */
parameter_list|,
specifier|const
name|Node
modifier|*
comment|/* relative */
parameter_list|)
block|{
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|markedUpEnumValue
name|QString
name|PlainCodeMarker
operator|::
name|markedUpEnumValue
parameter_list|(
specifier|const
name|QString
modifier|&
comment|/* enumValue */
parameter_list|,
specifier|const
name|Node
modifier|*
comment|/* relative */
parameter_list|)
block|{
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|markedUpIncludes
name|QString
name|PlainCodeMarker
operator|::
name|markedUpIncludes
parameter_list|(
specifier|const
name|QStringList
modifier|&
comment|/* includes */
parameter_list|)
block|{
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|functionBeginRegExp
name|QString
name|PlainCodeMarker
operator|::
name|functionBeginRegExp
parameter_list|(
specifier|const
name|QString
modifier|&
comment|/* funcName */
parameter_list|)
block|{
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|functionEndRegExp
name|QString
name|PlainCodeMarker
operator|::
name|functionEndRegExp
parameter_list|(
specifier|const
name|QString
modifier|&
comment|/* funcName */
parameter_list|)
block|{
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|sections
name|QList
argument_list|<
name|Section
argument_list|>
name|PlainCodeMarker
operator|::
name|sections
parameter_list|(
specifier|const
name|InnerNode
modifier|*
comment|/* innerNode */
parameter_list|,
name|SynopsisStyle
comment|/* style */
parameter_list|,
name|Status
comment|/* status */
parameter_list|)
block|{
return|return
name|QList
argument_list|<
name|Section
argument_list|>
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
