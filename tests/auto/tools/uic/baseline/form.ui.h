begin_unit
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'form.ui' ** ** Created: Fri Sep 4 10:17:13 2009 **      by: Qt User Interface Compiler version 4.6.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FORM_H
end_ifndef
begin_define
DECL|macro|FORM_H
define|#
directive|define
name|FORM_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QVariant>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QAction>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QApplication>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QButtonGroup>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QHBoxLayout>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QHeaderView>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QLabel>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QSpacerItem>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QSpinBox>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QTimeEdit>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QVBoxLayout>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QWidget>
end_include
begin_include
include|#
directive|include
file|"worldtimeclock.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Ui_WorldTimeForm
block|{
name|public
label|:
name|QHBoxLayout
modifier|*
name|hboxLayout
decl_stmt|;
name|WorldTimeClock
modifier|*
name|worldTimeClock
decl_stmt|;
name|QVBoxLayout
modifier|*
name|vboxLayout
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem
decl_stmt|;
name|QHBoxLayout
modifier|*
name|hboxLayout1
decl_stmt|;
name|QLabel
modifier|*
name|label
decl_stmt|;
name|QTimeEdit
modifier|*
name|timeEdit
decl_stmt|;
name|QHBoxLayout
modifier|*
name|hboxLayout2
decl_stmt|;
name|QLabel
modifier|*
name|label_2
decl_stmt|;
name|QSpinBox
modifier|*
name|spinBox
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem1
decl_stmt|;
name|void
name|setupUi
parameter_list|(
name|QWidget
modifier|*
name|WorldTimeForm
parameter_list|)
block|{
if|if
condition|(
name|WorldTimeForm
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|WorldTimeForm
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"WorldTimeForm"
argument_list|)
argument_list|)
expr_stmt|;
name|WorldTimeForm
operator|->
name|resize
argument_list|(
literal|400
argument_list|,
literal|300
argument_list|)
expr_stmt|;
name|hboxLayout
operator|=
name|new
name|QHBoxLayout
argument_list|(
name|WorldTimeForm
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|hboxLayout
operator|->
name|setSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|hboxLayout
operator|->
name|setContentsMargins
argument_list|(
literal|9
argument_list|,
literal|9
argument_list|,
literal|9
argument_list|,
literal|9
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|hboxLayout
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"hboxLayout"
argument_list|)
argument_list|)
expr_stmt|;
name|worldTimeClock
operator|=
name|new
name|WorldTimeClock
argument_list|(
name|WorldTimeForm
argument_list|)
expr_stmt|;
name|worldTimeClock
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"worldTimeClock"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|worldTimeClock
argument_list|)
expr_stmt|;
name|vboxLayout
operator|=
name|new
name|QVBoxLayout
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|vboxLayout
operator|->
name|setSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|vboxLayout
operator|->
name|setContentsMargins
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"vboxLayout"
argument_list|)
argument_list|)
expr_stmt|;
name|spacerItem
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|20
argument_list|,
literal|40
argument_list|,
name|QSizePolicy
operator|::
name|Minimum
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addItem
argument_list|(
name|spacerItem
argument_list|)
expr_stmt|;
name|hboxLayout1
operator|=
name|new
name|QHBoxLayout
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|hboxLayout1
operator|->
name|setSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|hboxLayout1
operator|->
name|setContentsMargins
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|hboxLayout1
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"hboxLayout1"
argument_list|)
argument_list|)
expr_stmt|;
name|label
operator|=
name|new
name|QLabel
argument_list|(
name|WorldTimeForm
argument_list|)
expr_stmt|;
name|label
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"label"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout1
operator|->
name|addWidget
argument_list|(
name|label
argument_list|)
expr_stmt|;
name|timeEdit
operator|=
name|new
name|QTimeEdit
argument_list|(
name|WorldTimeForm
argument_list|)
expr_stmt|;
name|timeEdit
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"timeEdit"
argument_list|)
argument_list|)
expr_stmt|;
name|timeEdit
operator|->
name|setReadOnly
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|hboxLayout1
operator|->
name|addWidget
argument_list|(
name|timeEdit
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addLayout
argument_list|(
name|hboxLayout1
argument_list|)
expr_stmt|;
name|hboxLayout2
operator|=
name|new
name|QHBoxLayout
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|hboxLayout2
operator|->
name|setSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|hboxLayout2
operator|->
name|setContentsMargins
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|hboxLayout2
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"hboxLayout2"
argument_list|)
argument_list|)
expr_stmt|;
name|label_2
operator|=
name|new
name|QLabel
argument_list|(
name|WorldTimeForm
argument_list|)
expr_stmt|;
name|label_2
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"label_2"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout2
operator|->
name|addWidget
argument_list|(
name|label_2
argument_list|)
expr_stmt|;
name|spinBox
operator|=
name|new
name|QSpinBox
argument_list|(
name|WorldTimeForm
argument_list|)
expr_stmt|;
name|spinBox
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"spinBox"
argument_list|)
argument_list|)
expr_stmt|;
name|spinBox
operator|->
name|setMaximum
argument_list|(
literal|12
argument_list|)
expr_stmt|;
name|spinBox
operator|->
name|setMinimum
argument_list|(
operator|-
literal|12
argument_list|)
expr_stmt|;
name|hboxLayout2
operator|->
name|addWidget
argument_list|(
name|spinBox
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addLayout
argument_list|(
name|hboxLayout2
argument_list|)
expr_stmt|;
name|spacerItem1
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|20
argument_list|,
literal|40
argument_list|,
name|QSizePolicy
operator|::
name|Minimum
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addItem
argument_list|(
name|spacerItem1
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addLayout
argument_list|(
name|vboxLayout
argument_list|)
expr_stmt|;
name|retranslateUi
argument_list|(
name|WorldTimeForm
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|spinBox
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|worldTimeClock
argument_list|,
name|SLOT
argument_list|(
name|setTimeZone
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|worldTimeClock
argument_list|,
name|SIGNAL
argument_list|(
name|updated
argument_list|(
name|QTime
argument_list|)
argument_list|)
argument_list|,
name|timeEdit
argument_list|,
name|SLOT
argument_list|(
name|setTime
argument_list|(
name|QTime
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|WorldTimeForm
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QWidget
modifier|*
name|WorldTimeForm
parameter_list|)
block|{
name|WorldTimeForm
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"WorldTimeForm"
argument_list|,
literal|"World Time Clock"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|label
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"WorldTimeForm"
argument_list|,
literal|"Current time:"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|label_2
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"WorldTimeForm"
argument_list|,
literal|"Set time zone:"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// retranslateUi
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|namespace
name|Ui
block|{
name|class
name|WorldTimeForm
range|:
name|public
name|Ui_WorldTimeForm
block|{}
decl_stmt|;
block|}
end_decl_stmt
begin_comment
comment|// namespace Ui
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// FORM_H
end_comment
end_unit
