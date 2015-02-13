begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"../tst_qmimedatabase.h"
end_include
begin_include
include|#
directive|include
file|<QDir>
end_include
begin_include
include|#
directive|include
file|<QFile>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qstandardpaths.h>
end_include
begin_include
include|#
directive|include
file|"../tst_qmimedatabase.cpp"
end_include
begin_function
DECL|function|init
name|void
name|tst_QMimeDatabase
operator|::
name|init
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|QT_NO_PROCESS
name|QSKIP
argument_list|(
literal|"No qprocess support"
argument_list|,
name|SkipAll
argument_list|)
expr_stmt|;
else|#
directive|else
specifier|const
name|QString
name|mimeDirName
init|=
name|m_globalXdgDir
operator|+
name|QStringLiteral
argument_list|(
literal|"/mime"
argument_list|)
decl_stmt|;
name|runUpdateMimeDatabase
argument_list|(
name|mimeDirName
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QFile
operator|::
name|exists
argument_list|(
name|mimeDirName
operator|+
name|QStringLiteral
argument_list|(
literal|"/mime.cache"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
end_unit
