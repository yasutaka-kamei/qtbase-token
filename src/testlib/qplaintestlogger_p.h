begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLAINTESTLOGGER_P_H
end_ifndef
begin_define
DECL|macro|QPLAINTESTLOGGER_P_H
define|#
directive|define
name|QPLAINTESTLOGGER_P_H
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
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QPlainTestLogger
range|:
name|public
name|QAbstractTestLogger
block|{
name|public
operator|:
name|QPlainTestLogger
argument_list|()
block|;
operator|~
name|QPlainTestLogger
argument_list|()
block|;
name|void
name|startLogging
argument_list|(
specifier|const
name|char
operator|*
name|filename
argument_list|)
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
argument|const char *message
argument_list|,
argument|const char *file =
literal|0
argument_list|,
argument|int line =
literal|0
argument_list|)
block|;
name|void
name|registerRandomSeed
argument_list|(
argument|unsigned int seed
argument_list|)
block|;
name|private
operator|:
name|unsigned
name|int
name|randomSeed
block|;
name|bool
name|hasRandomSeed
block|;
name|void
name|printMessage
argument_list|(
argument|const char *type
argument_list|,
argument|const char *msg
argument_list|,
argument|const char *file =
literal|0
argument_list|,
argument|int line =
literal|0
argument_list|)
block|;
name|void
name|outputMessage
argument_list|(
specifier|const
name|char
operator|*
name|str
argument_list|)
block|;
name|void
name|printBenchmarkResult
argument_list|(
specifier|const
name|QBenchmarkResult
operator|&
name|result
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
