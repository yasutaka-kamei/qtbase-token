begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Intel Corporation ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMACHPARSER_P_H
end_ifndef
begin_define
DECL|macro|QMACHPARSER_P_H
define|#
directive|define
name|QMACHPARSER_P_H
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
file|<qendian.h>
end_include
begin_include
include|#
directive|include
file|<qglobal.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
end_ifndef
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OF_MACH_O
argument_list|)
end_if
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QString
name|class
name|QString
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLibraryPrivate
name|class
name|QLibraryPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QMachOParser
block|{
name|public
label|:
enum|enum
block|{
name|QtMetaDataSection
block|,
name|NoQtSection
block|,
name|NotSuitable
block|}
enum|;
specifier|static
name|int
name|parse
parameter_list|(
specifier|const
name|char
modifier|*
name|m_s
parameter_list|,
name|ulong
name|fdlen
parameter_list|,
specifier|const
name|QString
modifier|&
name|library
parameter_list|,
name|QString
modifier|*
name|errorString
parameter_list|,
name|long
modifier|*
name|pos
parameter_list|,
name|ulong
modifier|*
name|sectionlen
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
comment|// defined(Q_OF_ELF)&& defined(Q_CC_GNU)
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_LIBRARY
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMACHPARSER_P_H
end_comment
end_unit
