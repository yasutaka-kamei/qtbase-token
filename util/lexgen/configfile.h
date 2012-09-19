begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the utils of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|CONFIGFILE_H
end_ifndef
begin_define
DECL|macro|CONFIGFILE_H
define|#
directive|define
name|CONFIGFILE_H
end_define
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<QMap>
end_include
begin_include
include|#
directive|include
file|<QVector>
end_include
begin_struct
DECL|struct|ConfigFile
struct|struct
name|ConfigFile
block|{
DECL|struct|Entry
struct|struct
name|Entry
block|{
DECL|function|Entry
specifier|inline
name|Entry
argument_list|()
operator|:
name|lineNumber
argument_list|(
argument|-
literal|1
argument_list|)
block|{}
DECL|member|lineNumber
name|int
name|lineNumber
expr_stmt|;
DECL|member|key
name|QString
name|key
decl_stmt|;
DECL|member|value
name|QString
name|value
decl_stmt|;
block|}
struct|;
name|struct
name|Section
range|:
name|public
name|QVector
operator|<
name|Entry
operator|>
block|{
specifier|inline
name|bool
name|contains
argument_list|(
argument|const QString&key
argument_list|)
specifier|const
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|key
operator|==
name|key
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
DECL|function|value
specifier|inline
name|QString
name|value
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|,
specifier|const
name|QString
operator|&
name|defaultValue
operator|=
name|QString
argument_list|()
argument_list|)
decl|const
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|key
operator|==
name|key
condition|)
return|return
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|value
return|;
return|return
name|defaultValue
return|;
block|}
block|}
struct|;
end_struct
begin_typedef
typedef|typedef
name|QMap
operator|<
name|QString
operator|,
name|Section
operator|>
name|SectionMap
expr_stmt|;
end_typedef
begin_function_decl
specifier|static
name|SectionMap
name|parse
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|SectionMap
name|parse
parameter_list|(
name|QIODevice
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl
begin_endif
unit|};
endif|#
directive|endif
end_endif
begin_comment
comment|// CONFIGFILE_H
end_comment
end_unit
