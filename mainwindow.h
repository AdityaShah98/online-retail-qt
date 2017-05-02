#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QListWidget>
#include <QGroupBox>
#include <QRadioButton>
#include <QComboBox>
#include <QCheckBox>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include <vector>
#include "mydatastore.h"
#include "user.h"
#include "product.h"
#include "util.h"

class MainWindow : public QWidget {
	Q_OBJECT

	public:
		MainWindow(MyDataStore*);
		~MainWindow();

	private slots:
		void search_product();
		void sort_results();
		//void select_user_combo();
		void select_user_combo(const QString &text);
		void select_user_button();
		void add_product_to_cart();
		void view_user_cart();
		void buy_user_cart();
		void cart_index_select(int index);
		void remove_from_cart();
		void display_review(int index);
		void sort_reviews(int state);
		void add_product_review_main();
		void add_product_review_window();
		//std::string parse_product_review();
		void save_database();
		void quit_program();
		
		
	private:
	   //void search_product();
	   std::string date_product_review();
	   int rating_product_review();
	   std::string review_product_review();
		
	private:
		void initializeComponents(MyDataStore*);
		void setupLayout();
		void connectEvents();
		void styleSheets();

	private:
	   MyDataStore* mydatastore;
	
		QVBoxLayout* overallLayout;
		
		QWidget* titlewidget;
		QWidget* searchwidget;
		QWidget* resultswidget;
		QWidget* reviewwidget;
		QWidget* savewidget;
		
		QHBoxLayout* titleLayout;
		QHBoxLayout* searchLayout;
		QHBoxLayout* resultsLayout;
		QHBoxLayout* reviewLayout;
		QHBoxLayout* saveLayout;
		
		QLabel* title;
		QWidget* user_widget;
		QGridLayout* user_grid;
		QLabel* current_user_label;
		QLabel* current_user;
		QLabel* current_balance_label;
		QLabel* current_balance;
		QComboBox* user_combo;
		QLineEdit* user_select;
		QPushButton* user_search;
		
		
		QLineEdit* search;
		QPushButton* searchButton;
		//QWidget* andorwidget;
		QVBoxLayout* andorLayout;
		QGroupBox* searchgroupBox;
		QRadioButton* orButton;
		QRadioButton* andButton;
		
		QListWidget* results;
		QWidget* optionswidget;
		QVBoxLayout* optionsLayout;
		//QWidget* sortwidget;
		QHBoxLayout* sortLayout;
		QGroupBox* sortgroupBox;
		QRadioButton* alphabeticalButton;
		QRadioButton* ratingButton;
		QPushButton* add_to_cart;
		QPushButton* view_cart;
		
		QListWidget* reviews;
		QWidget* sort_and_insert_widget;
		QVBoxLayout* sort_and_insert_layout;
		QCheckBox* sort_check;
		QPushButton* add_review;
		
		QPushButton* save;
		QPushButton* quit;
		
		QWidget* view_cart_widget;
		QVBoxLayout* view_cart_layout;
		QListWidget* user_cart;
		QWidget* view_cart_options_widget;
		QHBoxLayout* view_cart_options_layout;
		QPushButton* buy_cart;
		QPushButton* remove_item;
		
		QWidget* add_review_widget;
		QVBoxLayout* add_review_layout;
		QWidget* date_selection_widget;
		QHBoxLayout* date_selection_layout;
		QLabel* select_date;
		QComboBox* year_combo;
		QComboBox* month_combo;
		QComboBox* day_combo;
		QWidget* rating_and_review_widget;
		QHBoxLayout* rating_and_review_layout;
		QLabel* select_rating;
		QComboBox* rating_combo;
		QLabel* enter_review;
		QTextEdit* review_text;
		QPushButton* add_review_button;
		
		
	private:
		std::vector<Product*> product_results;
	   int current_product_index;	
		User* current;
		std::vector<Review*> current_reviews;
		std::vector<Product*> current_cart;
		int current_cart_index;
		
		
		
};

#endif

 
