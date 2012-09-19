begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_define
DECL|macro|QT_NO_KEYWORDS
define|#
directive|define
name|QT_NO_KEYWORDS
end_define
begin_undef
DECL|macro|signals
undef|#
directive|undef
name|signals
end_undef
begin_undef
DECL|macro|slots
undef|#
directive|undef
name|slots
end_undef
begin_undef
DECL|macro|emit
undef|#
directive|undef
name|emit
end_undef
begin_define
DECL|macro|signals
define|#
directive|define
name|signals
value|FooBar
end_define
begin_define
DECL|macro|slots
define|#
directive|define
name|slots
value|Baz
end_define
begin_define
DECL|macro|emit
define|#
directive|define
name|emit
value|Yoyodyne
end_define
begin_include
include|#
directive|include
file|<QtGui/QtGui>
end_include
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/QtNetwork>
end_include
begin_include
include|#
directive|include
file|<QtSql/QtSql>
end_include
begin_comment
comment|//#include<QtSvg>
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|WITH_DBUS
argument_list|)
end_if
begin_include
include|#
directive|include
file|<QtDBus>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|QT_SCRIPT_LIB
end_ifdef
begin_include
include|#
directive|include
file|<QtScript>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_undef
DECL|macro|signals
undef|#
directive|undef
name|signals
end_undef
begin_undef
DECL|macro|slots
undef|#
directive|undef
name|slots
end_undef
begin_undef
DECL|macro|emit
undef|#
directive|undef
name|emit
end_undef
begin_decl_stmt
name|class
name|MyBooooooostishClass
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
specifier|inline
name|MyBooooooostishClass
argument_list|()
block|{}
name|Q_SIGNALS
operator|:
name|void
name|mySignal
argument_list|()
block|;
name|public
name|Q_SLOTS
operator|:
specifier|inline
name|void
name|mySlot
argument_list|()
block|{
name|mySignal
argument_list|()
block|; }
name|private
operator|:
name|int
name|signals
block|;
name|double
name|slots
block|; }
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|signals
define|#
directive|define
name|signals
value|public
end_define
begin_define
DECL|macro|slots
define|#
directive|define
name|slots
end_define
begin_define
DECL|macro|emit
define|#
directive|define
name|emit
end_define
begin_undef
DECL|macro|QT_NO_KEYWORDS
undef|#
directive|undef
name|QT_NO_KEYWORDS
end_undef
end_unit
