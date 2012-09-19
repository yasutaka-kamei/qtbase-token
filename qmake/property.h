begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PROPERTY_H
end_ifndef
begin_define
DECL|macro|PROPERTY_H
define|#
directive|define
name|PROPERTY_H
end_define
begin_include
include|#
directive|include
file|"library/proitems.h"
end_include
begin_include
include|#
directive|include
file|<qglobal.h>
end_include
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_include
include|#
directive|include
file|<qhash.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QSettings
name|class
name|QSettings
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QMakeProperty
block|{
name|QSettings
modifier|*
name|settings
decl_stmt|;
name|void
name|initSettings
parameter_list|()
function_decl|;
name|QHash
operator|<
name|ProKey
operator|,
name|ProString
operator|>
name|m_values
expr_stmt|;
name|public
label|:
name|QMakeProperty
argument_list|()
expr_stmt|;
operator|~
name|QMakeProperty
argument_list|()
expr_stmt|;
name|bool
name|hasValue
parameter_list|(
specifier|const
name|ProKey
modifier|&
parameter_list|)
function_decl|;
name|ProString
name|value
parameter_list|(
specifier|const
name|ProKey
modifier|&
parameter_list|)
function_decl|;
name|void
name|setValue
parameter_list|(
name|QString
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
name|void
name|remove
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
name|bool
name|exec
parameter_list|()
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
comment|// PROPERTY_H
end_comment
end_unit
