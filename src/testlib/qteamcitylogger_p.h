begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 Borgar Ovsthus ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTEAMCITYLOGGER_P_H
end_ifndef
begin_define
DECL|macro|QTEAMCITYLOGGER_P_H
define|#
directive|define
name|QTEAMCITYLOGGER_P_H
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
file|<QtTest/private/qabstracttestlogger_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QTeamCityLogger
range|:
name|public
name|QAbstractTestLogger
block|{
name|public
operator|:
name|QTeamCityLogger
argument_list|(
specifier|const
name|char
operator|*
name|filename
argument_list|)
block|;
operator|~
name|QTeamCityLogger
argument_list|()
block|;
name|void
name|startLogging
argument_list|()
block|;
name|void
name|stopLogging
argument_list|()
block|;
name|void
name|enterTestFunction
argument_list|(
specifier|const
name|char
operator|*
name|function
argument_list|)
block|;
name|void
name|leaveTestFunction
argument_list|()
block|;
name|void
name|addIncident
argument_list|(
argument|IncidentTypes type
argument_list|,
argument|const char *description
argument_list|,
argument|const char *file =
literal|0
argument_list|,
argument|int line =
literal|0
argument_list|)
block|;
name|void
name|addBenchmarkResult
argument_list|(
specifier|const
name|QBenchmarkResult
operator|&
name|result
argument_list|)
block|;
name|void
name|addMessage
argument_list|(
argument|MessageTypes type
argument_list|,
argument|const QString&message
argument_list|,
argument|const char *file =
literal|0
argument_list|,
argument|int line =
literal|0
argument_list|)
block|;
name|private
operator|:
name|QString
name|currTestFuncName
block|;
name|QString
name|pendingMessages
block|;
name|QString
name|tcEscapedString
argument_list|(
argument|const QString&str
argument_list|)
specifier|const
block|;
name|QString
name|escapedTestFuncName
argument_list|()
specifier|const
block|;
name|void
name|addPendingMessage
argument_list|(
argument|const char *type
argument_list|,
argument|const QString&msg
argument_list|,
argument|const char *file
argument_list|,
argument|int line
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
