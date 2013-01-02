begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the qmake spec of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_define
DECL|macro|_POSIX_TIMERS
define|#
directive|define
name|_POSIX_TIMERS
end_define
begin_include
include|#
directive|include
file|"qglobal.h"
end_include
begin_comment
comment|// extra disabling.
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|__native_client__
end_ifdef
begin_define
DECL|macro|QT_NO_FSFILEENGINE
define|#
directive|define
name|QT_NO_FSFILEENGINE
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|QT_NO_SOCKET_H
define|#
directive|define
name|QT_NO_SOCKET_H
end_define
begin_define
DECL|macro|DIR
define|#
directive|define
name|DIR
value|void *
end_define
begin_define
DECL|macro|PATH_MAX
define|#
directive|define
name|PATH_MAX
value|256
end_define
begin_include
include|#
directive|include
file|"qfunctions_nacl.h"
end_include
begin_include
include|#
directive|include
file|<pthread.h>
end_include
end_unit
