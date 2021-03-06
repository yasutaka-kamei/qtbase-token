begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"classwizard.h"
end_include
begin_comment
comment|//! [0] //! [1]
end_comment
begin_constructor
DECL|function|ClassWizard
name|ClassWizard
operator|::
name|ClassWizard
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWizard
argument_list|(
name|parent
argument_list|)
block|{
name|addPage
argument_list|(
operator|new
name|IntroPage
argument_list|)
expr_stmt|;
name|addPage
argument_list|(
operator|new
name|ClassInfoPage
argument_list|)
expr_stmt|;
name|addPage
argument_list|(
operator|new
name|CodeStylePage
argument_list|)
expr_stmt|;
name|addPage
argument_list|(
operator|new
name|OutputFilesPage
argument_list|)
expr_stmt|;
name|addPage
argument_list|(
operator|new
name|ConclusionPage
argument_list|)
expr_stmt|;
comment|//! [0]
name|setPixmap
argument_list|(
name|QWizard
operator|::
name|BannerPixmap
argument_list|,
name|QPixmap
argument_list|(
literal|":/images/banner.png"
argument_list|)
argument_list|)
expr_stmt|;
name|setPixmap
argument_list|(
name|QWizard
operator|::
name|BackgroundPixmap
argument_list|,
name|QPixmap
argument_list|(
literal|":/images/background.png"
argument_list|)
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Class Wizard"
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [2]
block|}
end_constructor
begin_comment
comment|//! [1] //! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|accept
name|void
name|ClassWizard
operator|::
name|accept
parameter_list|()
comment|//! [3] //! [4]
block|{
name|QByteArray
name|className
init|=
name|field
argument_list|(
literal|"className"
argument_list|)
operator|.
name|toByteArray
argument_list|()
decl_stmt|;
name|QByteArray
name|baseClass
init|=
name|field
argument_list|(
literal|"baseClass"
argument_list|)
operator|.
name|toByteArray
argument_list|()
decl_stmt|;
name|QByteArray
name|macroName
init|=
name|field
argument_list|(
literal|"macroName"
argument_list|)
operator|.
name|toByteArray
argument_list|()
decl_stmt|;
name|QByteArray
name|baseInclude
init|=
name|field
argument_list|(
literal|"baseInclude"
argument_list|)
operator|.
name|toByteArray
argument_list|()
decl_stmt|;
name|QString
name|outputDir
init|=
name|field
argument_list|(
literal|"outputDir"
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|QString
name|header
init|=
name|field
argument_list|(
literal|"header"
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|QString
name|implementation
init|=
name|field
argument_list|(
literal|"implementation"
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
comment|//! [4]
name|QByteArray
name|block
decl_stmt|;
if|if
condition|(
name|field
argument_list|(
literal|"comment"
argument_list|)
operator|.
name|toBool
argument_list|()
condition|)
block|{
name|block
operator|+=
literal|"/*\n"
expr_stmt|;
name|block
operator|+=
literal|"    "
operator|+
name|header
operator|.
name|toLatin1
argument_list|()
operator|+
literal|'\n'
expr_stmt|;
name|block
operator|+=
literal|"*/\n"
expr_stmt|;
name|block
operator|+=
literal|'\n'
expr_stmt|;
block|}
if|if
condition|(
name|field
argument_list|(
literal|"protect"
argument_list|)
operator|.
name|toBool
argument_list|()
condition|)
block|{
name|block
operator|+=
literal|"#ifndef "
operator|+
name|macroName
operator|+
literal|'\n'
expr_stmt|;
name|block
operator|+=
literal|"#define "
operator|+
name|macroName
operator|+
literal|'\n'
expr_stmt|;
name|block
operator|+=
literal|'\n'
expr_stmt|;
block|}
if|if
condition|(
name|field
argument_list|(
literal|"includeBase"
argument_list|)
operator|.
name|toBool
argument_list|()
condition|)
block|{
name|block
operator|+=
literal|"#include "
operator|+
name|baseInclude
operator|+
literal|'\n'
expr_stmt|;
name|block
operator|+=
literal|'\n'
expr_stmt|;
block|}
name|block
operator|+=
literal|"class "
operator|+
name|className
expr_stmt|;
if|if
condition|(
operator|!
name|baseClass
operator|.
name|isEmpty
argument_list|()
condition|)
name|block
operator|+=
literal|" : public "
operator|+
name|baseClass
expr_stmt|;
name|block
operator|+=
literal|'\n'
expr_stmt|;
name|block
operator|+=
literal|"{\n"
expr_stmt|;
comment|/* qmake ignore Q_OBJECT */
if|if
condition|(
name|field
argument_list|(
literal|"qobjectMacro"
argument_list|)
operator|.
name|toBool
argument_list|()
condition|)
block|{
name|block
operator|+=
literal|"    Q_OBJECT\n"
expr_stmt|;
name|block
operator|+=
literal|'\n'
expr_stmt|;
block|}
name|block
operator|+=
literal|"public:\n"
expr_stmt|;
if|if
condition|(
name|field
argument_list|(
literal|"qobjectCtor"
argument_list|)
operator|.
name|toBool
argument_list|()
condition|)
block|{
name|block
operator|+=
literal|"    "
operator|+
name|className
operator|+
literal|"(QObject *parent = 0);\n"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|field
argument_list|(
literal|"qwidgetCtor"
argument_list|)
operator|.
name|toBool
argument_list|()
condition|)
block|{
name|block
operator|+=
literal|"    "
operator|+
name|className
operator|+
literal|"(QWidget *parent = 0);\n"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|field
argument_list|(
literal|"defaultCtor"
argument_list|)
operator|.
name|toBool
argument_list|()
condition|)
block|{
name|block
operator|+=
literal|"    "
operator|+
name|className
operator|+
literal|"();\n"
expr_stmt|;
if|if
condition|(
name|field
argument_list|(
literal|"copyCtor"
argument_list|)
operator|.
name|toBool
argument_list|()
condition|)
block|{
name|block
operator|+=
literal|"    "
operator|+
name|className
operator|+
literal|"(const "
operator|+
name|className
operator|+
literal|"&other);\n"
expr_stmt|;
name|block
operator|+=
literal|'\n'
expr_stmt|;
name|block
operator|+=
literal|"    "
operator|+
name|className
operator|+
literal|"&operator="
operator|+
literal|"(const "
operator|+
name|className
operator|+
literal|"&other);\n"
expr_stmt|;
block|}
block|}
name|block
operator|+=
literal|"};\n"
expr_stmt|;
if|if
condition|(
name|field
argument_list|(
literal|"protect"
argument_list|)
operator|.
name|toBool
argument_list|()
condition|)
block|{
name|block
operator|+=
literal|'\n'
expr_stmt|;
name|block
operator|+=
literal|"#endif\n"
expr_stmt|;
block|}
name|QFile
name|headerFile
argument_list|(
name|outputDir
operator|+
literal|'/'
operator|+
name|header
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|headerFile
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|WriteOnly
operator||
name|QFile
operator|::
name|Text
argument_list|)
condition|)
block|{
name|QMessageBox
operator|::
name|warning
argument_list|(
literal|0
argument_list|,
name|QObject
operator|::
name|tr
argument_list|(
literal|"Simple Wizard"
argument_list|)
argument_list|,
name|QObject
operator|::
name|tr
argument_list|(
literal|"Cannot write file %1:\n%2"
argument_list|)
operator|.
name|arg
argument_list|(
name|headerFile
operator|.
name|fileName
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|headerFile
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|headerFile
operator|.
name|write
argument_list|(
name|block
argument_list|)
expr_stmt|;
name|block
operator|.
name|clear
argument_list|()
expr_stmt|;
if|if
condition|(
name|field
argument_list|(
literal|"comment"
argument_list|)
operator|.
name|toBool
argument_list|()
condition|)
block|{
name|block
operator|+=
literal|"/*\n"
expr_stmt|;
name|block
operator|+=
literal|"    "
operator|+
name|implementation
operator|.
name|toLatin1
argument_list|()
operator|+
literal|'\n'
expr_stmt|;
name|block
operator|+=
literal|"*/\n"
expr_stmt|;
name|block
operator|+=
literal|'\n'
expr_stmt|;
block|}
name|block
operator|+=
literal|"#include \""
operator|+
name|header
operator|.
name|toLatin1
argument_list|()
operator|+
literal|"\"\n"
expr_stmt|;
name|block
operator|+=
literal|'\n'
expr_stmt|;
if|if
condition|(
name|field
argument_list|(
literal|"qobjectCtor"
argument_list|)
operator|.
name|toBool
argument_list|()
condition|)
block|{
name|block
operator|+=
name|className
operator|+
literal|"::"
operator|+
name|className
operator|+
literal|"(QObject *parent)\n"
expr_stmt|;
name|block
operator|+=
literal|"    : "
operator|+
name|baseClass
operator|+
literal|"(parent)\n"
expr_stmt|;
name|block
operator|+=
literal|"{\n"
expr_stmt|;
name|block
operator|+=
literal|"}\n"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|field
argument_list|(
literal|"qwidgetCtor"
argument_list|)
operator|.
name|toBool
argument_list|()
condition|)
block|{
name|block
operator|+=
name|className
operator|+
literal|"::"
operator|+
name|className
operator|+
literal|"(QWidget *parent)\n"
expr_stmt|;
name|block
operator|+=
literal|"    : "
operator|+
name|baseClass
operator|+
literal|"(parent)\n"
expr_stmt|;
name|block
operator|+=
literal|"{\n"
expr_stmt|;
name|block
operator|+=
literal|"}\n"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|field
argument_list|(
literal|"defaultCtor"
argument_list|)
operator|.
name|toBool
argument_list|()
condition|)
block|{
name|block
operator|+=
name|className
operator|+
literal|"::"
operator|+
name|className
operator|+
literal|"()\n"
expr_stmt|;
name|block
operator|+=
literal|"{\n"
expr_stmt|;
name|block
operator|+=
literal|"    // missing code\n"
expr_stmt|;
name|block
operator|+=
literal|"}\n"
expr_stmt|;
if|if
condition|(
name|field
argument_list|(
literal|"copyCtor"
argument_list|)
operator|.
name|toBool
argument_list|()
condition|)
block|{
name|block
operator|+=
literal|"\n"
expr_stmt|;
name|block
operator|+=
name|className
operator|+
literal|"::"
operator|+
name|className
operator|+
literal|"(const "
operator|+
name|className
operator|+
literal|"&other)\n"
expr_stmt|;
name|block
operator|+=
literal|"{\n"
expr_stmt|;
name|block
operator|+=
literal|"    *this = other;\n"
expr_stmt|;
name|block
operator|+=
literal|"}\n"
expr_stmt|;
name|block
operator|+=
literal|'\n'
expr_stmt|;
name|block
operator|+=
name|className
operator|+
literal|"&"
operator|+
name|className
operator|+
literal|"::operator=(const "
operator|+
name|className
operator|+
literal|"&other)\n"
expr_stmt|;
name|block
operator|+=
literal|"{\n"
expr_stmt|;
if|if
condition|(
operator|!
name|baseClass
operator|.
name|isEmpty
argument_list|()
condition|)
name|block
operator|+=
literal|"    "
operator|+
name|baseClass
operator|+
literal|"::operator=(other);\n"
expr_stmt|;
name|block
operator|+=
literal|"    // missing code\n"
expr_stmt|;
name|block
operator|+=
literal|"    return *this;\n"
expr_stmt|;
name|block
operator|+=
literal|"}\n"
expr_stmt|;
block|}
block|}
name|QFile
name|implementationFile
argument_list|(
name|outputDir
operator|+
literal|'/'
operator|+
name|implementation
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|implementationFile
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|WriteOnly
operator||
name|QFile
operator|::
name|Text
argument_list|)
condition|)
block|{
name|QMessageBox
operator|::
name|warning
argument_list|(
literal|0
argument_list|,
name|QObject
operator|::
name|tr
argument_list|(
literal|"Simple Wizard"
argument_list|)
argument_list|,
name|QObject
operator|::
name|tr
argument_list|(
literal|"Cannot write file %1:\n%2"
argument_list|)
operator|.
name|arg
argument_list|(
name|implementationFile
operator|.
name|fileName
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|implementationFile
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|implementationFile
operator|.
name|write
argument_list|(
name|block
argument_list|)
expr_stmt|;
comment|//! [5]
name|QDialog
operator|::
name|accept
argument_list|()
expr_stmt|;
comment|//! [5] //! [6]
block|}
end_function
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_constructor
DECL|function|IntroPage
name|IntroPage
operator|::
name|IntroPage
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWizardPage
argument_list|(
name|parent
argument_list|)
block|{
name|setTitle
argument_list|(
name|tr
argument_list|(
literal|"Introduction"
argument_list|)
argument_list|)
expr_stmt|;
name|setPixmap
argument_list|(
name|QWizard
operator|::
name|WatermarkPixmap
argument_list|,
name|QPixmap
argument_list|(
literal|":/images/watermark1.png"
argument_list|)
argument_list|)
expr_stmt|;
name|label
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"This wizard will generate a skeleton C++ class "
literal|"definition, including a few functions. You simply "
literal|"need to specify the class name and set a few "
literal|"options to produce a header file and an "
literal|"implementation file for your new C++ class."
argument_list|)
argument_list|)
expr_stmt|;
name|label
operator|->
name|setWordWrap
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|label
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8] //! [9]
end_comment
begin_constructor
DECL|function|ClassInfoPage
name|ClassInfoPage
operator|::
name|ClassInfoPage
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWizardPage
argument_list|(
name|parent
argument_list|)
block|{
comment|//! [8]
name|setTitle
argument_list|(
name|tr
argument_list|(
literal|"Class Information"
argument_list|)
argument_list|)
expr_stmt|;
name|setSubTitle
argument_list|(
name|tr
argument_list|(
literal|"Specify basic information about the class for which you "
literal|"want to generate skeleton source code files."
argument_list|)
argument_list|)
expr_stmt|;
name|setPixmap
argument_list|(
name|QWizard
operator|::
name|LogoPixmap
argument_list|,
name|QPixmap
argument_list|(
literal|":/images/logo1.png"
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [10]
name|classNameLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Class name:"
argument_list|)
argument_list|)
expr_stmt|;
name|classNameLineEdit
operator|=
operator|new
name|QLineEdit
expr_stmt|;
name|classNameLabel
operator|->
name|setBuddy
argument_list|(
name|classNameLineEdit
argument_list|)
expr_stmt|;
name|baseClassLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"B&ase class:"
argument_list|)
argument_list|)
expr_stmt|;
name|baseClassLineEdit
operator|=
operator|new
name|QLineEdit
expr_stmt|;
name|baseClassLabel
operator|->
name|setBuddy
argument_list|(
name|baseClassLineEdit
argument_list|)
expr_stmt|;
name|qobjectMacroCheckBox
operator|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Generate Q_OBJECT&macro"
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [10]
name|groupBox
operator|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"C&onstructor"
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [9]
name|qobjectCtorRadioButton
operator|=
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"&QObject-style constructor"
argument_list|)
argument_list|)
expr_stmt|;
name|qwidgetCtorRadioButton
operator|=
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"Q&Widget-style constructor"
argument_list|)
argument_list|)
expr_stmt|;
name|defaultCtorRadioButton
operator|=
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"&Default constructor"
argument_list|)
argument_list|)
expr_stmt|;
name|copyCtorCheckBox
operator|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"&Generate copy constructor and "
literal|"operator="
argument_list|)
argument_list|)
expr_stmt|;
name|defaultCtorRadioButton
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|defaultCtorRadioButton
argument_list|,
operator|&
name|QAbstractButton
operator|::
name|toggled
argument_list|,
name|copyCtorCheckBox
argument_list|,
operator|&
name|QWidget
operator|::
name|setEnabled
argument_list|)
expr_stmt|;
comment|//! [11] //! [12]
name|registerField
argument_list|(
literal|"className*"
argument_list|,
name|classNameLineEdit
argument_list|)
expr_stmt|;
name|registerField
argument_list|(
literal|"baseClass"
argument_list|,
name|baseClassLineEdit
argument_list|)
expr_stmt|;
name|registerField
argument_list|(
literal|"qobjectMacro"
argument_list|,
name|qobjectMacroCheckBox
argument_list|)
expr_stmt|;
comment|//! [11]
name|registerField
argument_list|(
literal|"qobjectCtor"
argument_list|,
name|qobjectCtorRadioButton
argument_list|)
expr_stmt|;
name|registerField
argument_list|(
literal|"qwidgetCtor"
argument_list|,
name|qwidgetCtorRadioButton
argument_list|)
expr_stmt|;
name|registerField
argument_list|(
literal|"defaultCtor"
argument_list|,
name|defaultCtorRadioButton
argument_list|)
expr_stmt|;
name|registerField
argument_list|(
literal|"copyCtor"
argument_list|,
name|copyCtorCheckBox
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|groupBoxLayout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
comment|//! [12]
name|groupBoxLayout
operator|->
name|addWidget
argument_list|(
name|qobjectCtorRadioButton
argument_list|)
expr_stmt|;
name|groupBoxLayout
operator|->
name|addWidget
argument_list|(
name|qwidgetCtorRadioButton
argument_list|)
expr_stmt|;
name|groupBoxLayout
operator|->
name|addWidget
argument_list|(
name|defaultCtorRadioButton
argument_list|)
expr_stmt|;
name|groupBoxLayout
operator|->
name|addWidget
argument_list|(
name|copyCtorCheckBox
argument_list|)
expr_stmt|;
name|groupBox
operator|->
name|setLayout
argument_list|(
name|groupBoxLayout
argument_list|)
expr_stmt|;
name|QGridLayout
modifier|*
name|layout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|classNameLabel
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|classNameLineEdit
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|baseClassLabel
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|baseClassLineEdit
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|qobjectMacroCheckBox
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|groupBox
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
comment|//! [13]
block|}
end_constructor
begin_comment
comment|//! [13]
end_comment
begin_comment
comment|//! [14]
end_comment
begin_constructor
DECL|function|CodeStylePage
name|CodeStylePage
operator|::
name|CodeStylePage
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWizardPage
argument_list|(
name|parent
argument_list|)
block|{
name|setTitle
argument_list|(
name|tr
argument_list|(
literal|"Code Style Options"
argument_list|)
argument_list|)
expr_stmt|;
name|setSubTitle
argument_list|(
name|tr
argument_list|(
literal|"Choose the formatting of the generated code."
argument_list|)
argument_list|)
expr_stmt|;
name|setPixmap
argument_list|(
name|QWizard
operator|::
name|LogoPixmap
argument_list|,
name|QPixmap
argument_list|(
literal|":/images/logo2.png"
argument_list|)
argument_list|)
expr_stmt|;
name|commentCheckBox
operator|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"&Start generated files with a "
comment|//! [14]
literal|"comment"
argument_list|)
argument_list|)
expr_stmt|;
name|commentCheckBox
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|protectCheckBox
operator|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"&Protect header file against multiple "
literal|"inclusions"
argument_list|)
argument_list|)
expr_stmt|;
name|protectCheckBox
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|macroNameLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Macro name:"
argument_list|)
argument_list|)
expr_stmt|;
name|macroNameLineEdit
operator|=
operator|new
name|QLineEdit
expr_stmt|;
name|macroNameLabel
operator|->
name|setBuddy
argument_list|(
name|macroNameLineEdit
argument_list|)
expr_stmt|;
name|includeBaseCheckBox
operator|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"&Include base class definition"
argument_list|)
argument_list|)
expr_stmt|;
name|baseIncludeLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Base class include:"
argument_list|)
argument_list|)
expr_stmt|;
name|baseIncludeLineEdit
operator|=
operator|new
name|QLineEdit
expr_stmt|;
name|baseIncludeLabel
operator|->
name|setBuddy
argument_list|(
name|baseIncludeLineEdit
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|protectCheckBox
argument_list|,
operator|&
name|QAbstractButton
operator|::
name|toggled
argument_list|,
name|macroNameLabel
argument_list|,
operator|&
name|QWidget
operator|::
name|setEnabled
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|protectCheckBox
argument_list|,
operator|&
name|QAbstractButton
operator|::
name|toggled
argument_list|,
name|macroNameLineEdit
argument_list|,
operator|&
name|QWidget
operator|::
name|setEnabled
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|includeBaseCheckBox
argument_list|,
operator|&
name|QAbstractButton
operator|::
name|toggled
argument_list|,
name|baseIncludeLabel
argument_list|,
operator|&
name|QWidget
operator|::
name|setEnabled
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|includeBaseCheckBox
argument_list|,
operator|&
name|QAbstractButton
operator|::
name|toggled
argument_list|,
name|baseIncludeLineEdit
argument_list|,
operator|&
name|QWidget
operator|::
name|setEnabled
argument_list|)
expr_stmt|;
name|registerField
argument_list|(
literal|"comment"
argument_list|,
name|commentCheckBox
argument_list|)
expr_stmt|;
name|registerField
argument_list|(
literal|"protect"
argument_list|,
name|protectCheckBox
argument_list|)
expr_stmt|;
name|registerField
argument_list|(
literal|"macroName"
argument_list|,
name|macroNameLineEdit
argument_list|)
expr_stmt|;
name|registerField
argument_list|(
literal|"includeBase"
argument_list|,
name|includeBaseCheckBox
argument_list|)
expr_stmt|;
name|registerField
argument_list|(
literal|"baseInclude"
argument_list|,
name|baseIncludeLineEdit
argument_list|)
expr_stmt|;
name|QGridLayout
modifier|*
name|layout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|layout
operator|->
name|setColumnMinimumWidth
argument_list|(
literal|0
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|commentCheckBox
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|protectCheckBox
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|macroNameLabel
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|macroNameLineEdit
argument_list|,
literal|2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|includeBaseCheckBox
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|baseIncludeLabel
argument_list|,
literal|4
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|baseIncludeLineEdit
argument_list|,
literal|4
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|//! [15]
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [15]
end_comment
begin_comment
comment|//! [16]
end_comment
begin_function
DECL|function|initializePage
name|void
name|CodeStylePage
operator|::
name|initializePage
parameter_list|()
block|{
name|QString
name|className
init|=
name|field
argument_list|(
literal|"className"
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|macroNameLineEdit
operator|->
name|setText
argument_list|(
name|className
operator|.
name|toUpper
argument_list|()
operator|+
literal|"_H"
argument_list|)
expr_stmt|;
name|QString
name|baseClass
init|=
name|field
argument_list|(
literal|"baseClass"
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|includeBaseCheckBox
operator|->
name|setChecked
argument_list|(
operator|!
name|baseClass
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|includeBaseCheckBox
operator|->
name|setEnabled
argument_list|(
operator|!
name|baseClass
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|baseIncludeLabel
operator|->
name|setEnabled
argument_list|(
operator|!
name|baseClass
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|baseIncludeLineEdit
operator|->
name|setEnabled
argument_list|(
operator|!
name|baseClass
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|baseClass
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|baseIncludeLineEdit
operator|->
name|clear
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|QRegExp
argument_list|(
literal|"Q[A-Z].*"
argument_list|)
operator|.
name|exactMatch
argument_list|(
name|baseClass
argument_list|)
condition|)
block|{
name|baseIncludeLineEdit
operator|->
name|setText
argument_list|(
literal|'<'
operator|+
name|baseClass
operator|+
literal|'>'
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|baseIncludeLineEdit
operator|->
name|setText
argument_list|(
literal|'"'
operator|+
name|baseClass
operator|.
name|toLower
argument_list|()
operator|+
literal|".h\""
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [16]
end_comment
begin_constructor
DECL|function|OutputFilesPage
name|OutputFilesPage
operator|::
name|OutputFilesPage
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWizardPage
argument_list|(
name|parent
argument_list|)
block|{
name|setTitle
argument_list|(
name|tr
argument_list|(
literal|"Output Files"
argument_list|)
argument_list|)
expr_stmt|;
name|setSubTitle
argument_list|(
name|tr
argument_list|(
literal|"Specify where you want the wizard to put the generated "
literal|"skeleton code."
argument_list|)
argument_list|)
expr_stmt|;
name|setPixmap
argument_list|(
name|QWizard
operator|::
name|LogoPixmap
argument_list|,
name|QPixmap
argument_list|(
literal|":/images/logo3.png"
argument_list|)
argument_list|)
expr_stmt|;
name|outputDirLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Output directory:"
argument_list|)
argument_list|)
expr_stmt|;
name|outputDirLineEdit
operator|=
operator|new
name|QLineEdit
expr_stmt|;
name|outputDirLabel
operator|->
name|setBuddy
argument_list|(
name|outputDirLineEdit
argument_list|)
expr_stmt|;
name|headerLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Header file name:"
argument_list|)
argument_list|)
expr_stmt|;
name|headerLineEdit
operator|=
operator|new
name|QLineEdit
expr_stmt|;
name|headerLabel
operator|->
name|setBuddy
argument_list|(
name|headerLineEdit
argument_list|)
expr_stmt|;
name|implementationLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Implementation file name:"
argument_list|)
argument_list|)
expr_stmt|;
name|implementationLineEdit
operator|=
operator|new
name|QLineEdit
expr_stmt|;
name|implementationLabel
operator|->
name|setBuddy
argument_list|(
name|implementationLineEdit
argument_list|)
expr_stmt|;
name|registerField
argument_list|(
literal|"outputDir*"
argument_list|,
name|outputDirLineEdit
argument_list|)
expr_stmt|;
name|registerField
argument_list|(
literal|"header*"
argument_list|,
name|headerLineEdit
argument_list|)
expr_stmt|;
name|registerField
argument_list|(
literal|"implementation*"
argument_list|,
name|implementationLineEdit
argument_list|)
expr_stmt|;
name|QGridLayout
modifier|*
name|layout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|outputDirLabel
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|outputDirLineEdit
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|headerLabel
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|headerLineEdit
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|implementationLabel
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|implementationLineEdit
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [17]
end_comment
begin_function
DECL|function|initializePage
name|void
name|OutputFilesPage
operator|::
name|initializePage
parameter_list|()
block|{
name|QString
name|className
init|=
name|field
argument_list|(
literal|"className"
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|headerLineEdit
operator|->
name|setText
argument_list|(
name|className
operator|.
name|toLower
argument_list|()
operator|+
literal|".h"
argument_list|)
expr_stmt|;
name|implementationLineEdit
operator|->
name|setText
argument_list|(
name|className
operator|.
name|toLower
argument_list|()
operator|+
literal|".cpp"
argument_list|)
expr_stmt|;
name|outputDirLineEdit
operator|->
name|setText
argument_list|(
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|QDir
operator|::
name|tempPath
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [17]
end_comment
begin_constructor
DECL|function|ConclusionPage
name|ConclusionPage
operator|::
name|ConclusionPage
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWizardPage
argument_list|(
name|parent
argument_list|)
block|{
name|setTitle
argument_list|(
name|tr
argument_list|(
literal|"Conclusion"
argument_list|)
argument_list|)
expr_stmt|;
name|setPixmap
argument_list|(
name|QWizard
operator|::
name|WatermarkPixmap
argument_list|,
name|QPixmap
argument_list|(
literal|":/images/watermark2.png"
argument_list|)
argument_list|)
expr_stmt|;
name|label
operator|=
operator|new
name|QLabel
expr_stmt|;
name|label
operator|->
name|setWordWrap
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|label
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|initializePage
name|void
name|ConclusionPage
operator|::
name|initializePage
parameter_list|()
block|{
name|QString
name|finishText
init|=
name|wizard
argument_list|()
operator|->
name|buttonText
argument_list|(
name|QWizard
operator|::
name|FinishButton
argument_list|)
decl_stmt|;
name|finishText
operator|.
name|remove
argument_list|(
literal|'&'
argument_list|)
expr_stmt|;
name|label
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Click %1 to generate the class skeleton."
argument_list|)
operator|.
name|arg
argument_list|(
name|finishText
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
