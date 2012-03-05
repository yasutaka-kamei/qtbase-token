begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 KlarÃ¤lvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author Marc Mutz<marc.mutz@kdab.com> ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|TESTS_AUTO_CORELIB_TOOLS_MOC_CXX11_FINAL_CLASSES_H
end_ifndef
begin_define
DECL|macro|TESTS_AUTO_CORELIB_TOOLS_MOC_CXX11_FINAL_CLASSES_H
define|#
directive|define
name|TESTS_AUTO_CORELIB_TOOLS_MOC_CXX11_FINAL_CLASSES_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QObject>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|Q_MOC_RUN
end_ifndef
begin_comment
comment|// hide from moc
end_comment
begin_define
DECL|macro|final
define|#
directive|define
name|final
end_define
begin_define
DECL|macro|sealed
define|#
directive|define
name|sealed
end_define
begin_define
DECL|macro|EXPORT_MACRO
define|#
directive|define
name|EXPORT_MACRO
end_define
begin_define
DECL|macro|EXPORT_MACRO2
define|#
directive|define
name|EXPORT_MACRO2
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|,
name|Z
parameter_list|)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|class
name|FinalTestClassQt
name|Q_DECL_FINAL
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|FinalTestClassQt
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
operator|:
name|QObject
argument_list|(
argument|parent
argument_list|)
block|{}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|EXPORT_MACRO
name|ExportedFinalTestClassQt
name|Q_DECL_FINAL
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|ExportedFinalTestClassQt
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
operator|:
name|QObject
argument_list|(
argument|parent
argument_list|)
block|{}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|function|EXPORT_MACRO2
name|class
name|EXPORT_MACRO2
argument_list|(
name|X
argument_list|,
name|Y
argument_list|,
name|Z
argument_list|)
name|ExportedFinalTestClassQtX
name|Q_DECL_FINAL
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|ExportedFinalTestClassQtX
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
operator|:
name|QObject
argument_list|(
argument|parent
argument_list|)
block|{}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|FinalTestClassCpp11
name|final
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|FinalTestClassCpp11
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
operator|:
name|QObject
argument_list|(
argument|parent
argument_list|)
block|{}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|EXPORT_MACRO
name|ExportedFinalTestClassCpp11
name|final
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|ExportedFinalTestClassCpp11
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
operator|:
name|QObject
argument_list|(
argument|parent
argument_list|)
block|{}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|function|EXPORT_MACRO2
name|class
name|EXPORT_MACRO2
argument_list|(
name|X
argument_list|,
name|Y
argument_list|,
name|Z
argument_list|)
name|ExportedFinalTestClassCpp11X
name|final
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|ExportedFinalTestClassCpp11X
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
operator|:
name|QObject
argument_list|(
argument|parent
argument_list|)
block|{}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|SealedTestClass
name|sealed
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|SealedTestClass
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
operator|:
name|QObject
argument_list|(
argument|parent
argument_list|)
block|{}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|EXPORT_MACRO
name|ExportedSealedTestClass
name|sealed
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|ExportedSealedTestClass
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
operator|:
name|QObject
argument_list|(
argument|parent
argument_list|)
block|{}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|function|EXPORT_MACRO2
name|class
name|EXPORT_MACRO2
argument_list|(
name|X
argument_list|,
name|Y
argument_list|,
name|Z
argument_list|)
name|ExportedSealedTestClassX
name|sealed
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|ExportedSealedTestClassX
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
operator|:
name|QObject
argument_list|(
argument|parent
argument_list|)
block|{}
block|}
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|Q_MOC_RUN
end_ifndef
begin_undef
DECL|macro|final
undef|#
directive|undef
name|final
end_undef
begin_undef
DECL|macro|sealed
undef|#
directive|undef
name|sealed
end_undef
begin_undef
DECL|macro|EXPORT_MACRO
undef|#
directive|undef
name|EXPORT_MACRO
end_undef
begin_undef
DECL|macro|EXPORT_MACRO2
undef|#
directive|undef
name|EXPORT_MACRO2
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// TESTS_AUTO_CORELIB_TOOLS_MOC_CXX11_FINAL_CLASSES_H
end_comment
end_unit
