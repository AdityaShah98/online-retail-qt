#include <QLabel>
#include <QMessageBox>
#include <QApplication>
#include <QString>
#include <iostream>
#include <sstream>
#include <set>
#include <QFileDialog>
#include <QFont>
#include <fstream>
#include "mainwindow.h"
#include "msort.h"

struct AlphabeticalComp
{
   bool operator()(const Product* lhs, const Product* rhs)
   {
      return lhs->getName() < rhs->getName();
   }

};

struct RatingComp
{
    bool operator()(const Product* lhs, const Product* rhs)
   {
      return lhs->average_rating >= rhs->average_rating;
   }

};

struct ReviewComp
{
    bool operator()(const Review* lhs, const Review* rhs)
   {
      return lhs->date >= rhs->date;
   }

};

MainWindow::MainWindow(MyDataStore* mds)
{
	
  
	initializeComponents(mds);
	setupLayout();
	connectEvents();
	styleSheets();
	
	current_product_index = -1; 
	current_cart_index = -1;
	
	setLayout(overallLayout);
	show();
	
}


MainWindow::~MainWindow()
{
	
}

void MainWindow::initializeComponents(MyDataStore* mds)
{
	mydatastore = mds;
	
	overallLayout = new QVBoxLayout();
	
	titlewidget = new QWidget();
	searchwidget = new QWidget();
	resultswidget = new QWidget();
   reviewwidget = new QWidget();
	savewidget = new QWidget();
	
	titleLayout = new QHBoxLayout();
	searchLayout = new QHBoxLayout();
	resultsLayout = new QHBoxLayout();
	reviewLayout = new QHBoxLayout();
	saveLayout = new QHBoxLayout();
	
	title = new QLabel("Welcome to Amazon,");
	QFont titleFont;
   titleFont.setBold(true);
   titleFont.setPointSize(14);
   title->setFont(titleFont);
	user_widget = new QWidget();
	user_grid = new QGridLayout();
	//current_user = new QLabel(); add connection to current user in the drop-down
	user_combo = new QComboBox();
	std::set<User*> temp=mydatastore->get_user_set();
	std::set<User*>::iterator it;
	it=temp.begin();
	current = *it;
	for(;it!=temp.end();++it)
	{
	   user_combo->addItem(QString::fromStdString((*it)->getName()));
	}
	
	current_user_label = new QLabel("Current User: ");
	current_user_label->setFont(titleFont);
	current_user = new QLabel((QString::fromStdString(current->getName())));
	current_user->setFont(titleFont);
	current_balance_label = new QLabel("Your balance is $");
	current_balance_label->setFont(titleFont);
	current_balance = new QLabel((QString::number(current->getBalance())));
	current_balance->setFont(titleFont);
	user_select = new QLineEdit();
	user_search = new QPushButton("Select User");
	
	search = new QLineEdit();
	searchButton = new QPushButton("Search");
	//andorwidget = new QWidget();
	andorLayout = new QVBoxLayout();
	searchgroupBox = new QGroupBox("Search Options: ");
	orButton = new QRadioButton("OR");
	andButton = new QRadioButton("AND");
	
	results = new QListWidget();
	optionswidget = new QWidget();
	optionsLayout = new QVBoxLayout();
	//sortwidget = new QWidget();
	sortLayout = new QHBoxLayout();
	sortgroupBox = new QGroupBox("Sort By: ");
	alphabeticalButton = new QRadioButton("Alphabetical Order");
	ratingButton = new QRadioButton("Rating");
	add_to_cart = new QPushButton("Add To Cart");
	view_cart = new QPushButton("View Cart");
	
	reviews = new QListWidget();
	sort_and_insert_widget = new QWidget();
   sort_and_insert_layout = new QVBoxLayout();
	sort_check = new QCheckBox("Sort Reviews by Date");
   add_review = new QPushButton("Add Review");
	
	save = new QPushButton("Save");
	quit = new QPushButton("Quit");
	
	view_cart_widget = new QWidget();
	view_cart_layout = new QVBoxLayout;
   user_cart = new QListWidget();
   view_cart_options_widget = new QWidget();
   view_cart_options_layout = new QHBoxLayout();
	buy_cart = new QPushButton("Buy Cart");
	remove_item = new QPushButton("Remove Product");
	
	add_review_widget = new QWidget();
	add_review_layout = new QVBoxLayout();
	date_selection_widget = new QWidget();
	date_selection_layout = new QHBoxLayout();
	select_date = new QLabel("Select Date: ");
   year_combo = new QComboBox();
   for(int i=2016;i<=2030;i++)
	{
	   year_combo->addItem(QString::number(i));
	}
	month_combo = new QComboBox();
	for(int i=1;i<=12;i++)
	{
	   month_combo->addItem(QString::number(i));
	}
	day_combo = new QComboBox();
	for(int i=1;i<=31;i++)
	{
	   day_combo->addItem(QString::number(i));
	}
	rating_and_review_widget = new QWidget();
	rating_and_review_layout = new QHBoxLayout();
	select_rating = new QLabel("Select Rating: ");
	rating_combo = new QComboBox();
	for(int i=1;i<=5;i++)
	{
	   rating_combo->addItem(QString::number(i));
	}
	enter_review = new QLabel("Enter Review: ");
	review_text = new QTextEdit();
	add_review_button = new QPushButton("Add Review For Product");

}

void MainWindow::setupLayout()
{
	titlewidget->setLayout(titleLayout);
	searchwidget->setLayout(searchLayout);
	resultswidget->setLayout(resultsLayout);
	reviewwidget->setLayout(reviewLayout);
	savewidget->setLayout(saveLayout);
	
	overallLayout->addWidget(titlewidget);
	overallLayout->addWidget(searchwidget);
	overallLayout->addWidget(resultswidget);
	overallLayout->addWidget(reviewwidget);
	overallLayout->addWidget(savewidget);
	
	//titleLayout->addWidget(title);
	//titleLayout->addWidget(user_widget);
	//user_widget->setLayout(user_grid);
	//user_grid->addWidget(current_user, 0, 0, 1, 1);
	//user_grid->addWidget(user_combo, 0, 1, 1, 1);
	//user_grid->addWidget(user_select, 1, 0, 1, 1);
	//user_grid->addWidget(user_search, 1, 1, 1, 1);
	
	//titleLayout->addWidget(title);
	//titleLayout->addWidget(user_widget);
	//user_widget->setLayout(user_grid);
	//user_grid->addWidget(current_user_label, 0, 0, 1, 5);
	//user_grid->addWidget(current_user, 0, 5, 1, 5);
	//user_grid->addWidget(current_balance_label, 1, 0, 1, 5);
	//user_grid->addWidget(current_balance, 1, 5, 1, 5);
	//titleLayout->addWidget(user_combo);
	
	titleLayout->addWidget(user_widget);
	user_widget->setLayout(user_grid);
	user_grid->addWidget(title, 0, 0, 1, 1);
	user_grid->addWidget(current_user, 0, 1, 1, 1);
	user_grid->addWidget(current_balance_label, 1, 0, 1, 1);
	user_grid->addWidget(current_balance, 1, 1, 1, 1);
	//titleLayout->addWidget(user_widget);
	//user_widget->setLayout(user_grid);
	//user_grid->addWidget(current_balance_label, 1, 0, 1, 5);
	//user_grid->addWidget(current_balance, 1, 5, 1, 5);
	titleLayout->addWidget(user_combo);
	
	searchLayout->addWidget(search);
	searchLayout->addWidget(searchButton);
	searchLayout->addWidget(searchgroupBox);
	searchgroupBox->setLayout(andorLayout);
	andorLayout->addWidget(orButton);
	andorLayout->addWidget(andButton);
	
	resultsLayout->addWidget(results);
	resultsLayout->addWidget(optionswidget);
	optionswidget->setLayout(optionsLayout);
	optionsLayout->addWidget(sortgroupBox);
	sortgroupBox->setLayout(sortLayout);
	sortLayout->addWidget(alphabeticalButton);
	sortLayout->addWidget(ratingButton);
	optionsLayout->addWidget(add_to_cart);
	optionsLayout->addWidget(view_cart);
	
	reviewLayout->addWidget(reviews);
   reviewLayout->addWidget(sort_and_insert_widget);
   sort_and_insert_widget->setLayout(sort_and_insert_layout);
   sort_and_insert_layout->addWidget(sort_check);
   sort_and_insert_layout->addWidget( add_review);   
   
   saveLayout->addWidget(save);
   saveLayout->addWidget(quit);
   
   view_cart_widget->setLayout(view_cart_layout);
	view_cart_layout->addWidget(user_cart);
   view_cart_layout->addWidget(view_cart_options_widget);
   view_cart_options_widget->setLayout(view_cart_options_layout);
   view_cart_options_layout->addWidget(buy_cart);
	view_cart_options_layout->addWidget(remove_item);
	
	add_review_widget->setLayout(add_review_layout);
	add_review_layout->addWidget(date_selection_widget);
	date_selection_widget->setLayout(date_selection_layout);
	date_selection_layout->addWidget(select_date);
	date_selection_layout->addWidget(year_combo);
   date_selection_layout->addWidget(month_combo);
   date_selection_layout->addWidget(day_combo);
   add_review_layout->addWidget(rating_and_review_widget);
   rating_and_review_widget->setLayout(rating_and_review_layout);
   rating_and_review_layout->addWidget(select_rating);
   rating_and_review_layout->addWidget(rating_combo);
   rating_and_review_layout->addWidget(enter_review);
   rating_and_review_layout->addWidget(review_text);
	add_review_layout->addWidget(add_review_button);
   
}

void MainWindow::connectEvents()
{
   connect(searchButton, SIGNAL(clicked()), this, SLOT(search_product()));
   connect(alphabeticalButton, SIGNAL(clicked()), this, SLOT(sort_results()));
   connect(ratingButton, SIGNAL(clicked()), this, SLOT(sort_results()));
   //connect(user_combo, SIGNAL(clicked()), this, SLOT(select_user_combo()));
   connect(user_combo, SIGNAL(activated(const QString)), 
   this, SLOT(select_user_combo(const QString)));
   connect(user_search, SIGNAL(clicked()), this, SLOT(select_user_button()));
   connect(quit, SIGNAL(clicked()), this, SLOT(quit_program()));
   connect(save, SIGNAL(clicked()), this, SLOT(save_database()));
   connect(results, SIGNAL(currentRowChanged(int)), this, SLOT(display_review(int)));
   connect(sort_check, SIGNAL(stateChanged(int)), this, SLOT(sort_reviews(int)));
   connect(add_to_cart, SIGNAL(clicked()), this, SLOT(add_product_to_cart()));
   connect(view_cart, SIGNAL(clicked()), this, SLOT(view_user_cart()));
   connect(buy_cart, SIGNAL(clicked()), this, SLOT(buy_user_cart()));
   connect(user_cart, SIGNAL(currentRowChanged(int)), this, SLOT(cart_index_select(int)));
   connect(remove_item, SIGNAL(clicked()), this, SLOT(remove_from_cart()));
   connect(add_review, SIGNAL(clicked()), this, SLOT(add_product_review_main()));
   connect(add_review_button, SIGNAL(clicked()), this, SLOT(add_product_review_window()));
   
}

void MainWindow::styleSheets()
{
    setStyleSheet(
    "QCheckBox{spacing: 5px;}"
    "QCheckBox::indicator {width: 13px; height: 13px;}"
    "QComboBox {border: 1px solid gray; border-radius: 3px; padding: 1px 18px 1px 3px; min-width: 6em;}"
    "QComboBox:editable {background: white;}"
    "QComboBox:!editable, QComboBox::drop-down:editable {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);}"
    "QComboBox:!editable:on, QComboBox::drop-down:editable:on {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #D3D3D3, stop: 0.4 #D8D8D8,stop: 0.5 #DDDDDD, stop: 1.0 #E1E1E1);}"
    "QComboBox:on { padding-top: 3px;padding-left: 4px;}"
    //"QComboBox::drop-down {subcontrol-origin: padding;subcontrol-position: top right;width: 15px;border-left-width: 1px;border-left-color: darkgray;border-left-style: solid; border-top-right-radius: 3px; border-bottom-right-radius: 3px;}"
    "QComboBox::down-arrow:on {top: 1px;left: 1px;}"
    "QComboBox QAbstractItemView {border: 2px solid darkgray;selection-background-color: lightgray;}"
    "QPushButton {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);border-style: outset;border-width: 2px;border-radius: 10px;border-color: darkgray;font: bold 14px;min-width: 10em;padding: 6px;}"
    "QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3)}"
    "QGroupBox {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #E0E0E0, stop: 1 #FFFFFF);}"
    
    "QTextEdit{background-color: #ffffff}"
    "QLineEdit{background-color: #ffffff}"
    
    
    );
    //QApplication::setStyleSheet("stylesheet.qss");
    
    
    

}


void MainWindow::search_product()
{
   
   current_product_index = -1; 
	current_cart_index = -1;
   
   if(search->text().isEmpty() || (!(orButton->isChecked()) && !(andButton->isChecked())))
   {
      QMessageBox::information(this, "Invalid Keyword(s)", "Please type keyword(s) to search");
      return;
   }
   else
   {
      
      results->clear();
      product_results.clear();	
      current_reviews.clear();
      reviews->clear();
      
      std::string temp = search->text().toStdString();
      std::stringstream ss(temp);
      std::string term;
      std::vector<std::string> terms_;
      int type_;
      std::vector<Product*> product_vector;
     
      
      if(orButton->isChecked())
      {
         type_ = 1;
      }
      else
      {
         type_ = 0;
      }
      while(ss >> term)
      {
         term=convToLower(term);
         terms_.push_back(term);
      }
      
      product_vector = mydatastore->search(terms_, type_);
      
     
      for(unsigned int i=0; i<product_vector.size(); i++)
      {
         results->addItem(QString::fromStdString(product_vector[i]->displayString()));
         product_results.push_back(product_vector[i]);
      }
      
      if(alphabeticalButton->isChecked() || ratingButton->isChecked())
      {
         sort_results();
      }
   
   }

}

void MainWindow::sort_results()
{
   //mergeSort(u, l2);
   if(product_results.size() == 0 || (!(alphabeticalButton->isChecked()) && !(ratingButton->isChecked())))
   {
      return;
   }
   else
   {
      if(alphabeticalButton->isChecked())
      {
         results->clear();
         //product_results.clear();
         AlphabeticalComp a;
         mergeSort(product_results, a);
         for(unsigned int i=0; i<product_results.size(); i++)
         {
            results->addItem(QString::fromStdString(product_results[i]->displayString()));
         }
         
      }
      else
      {
         results->clear();
         RatingComp r;
         for(unsigned int i=0; i<product_results.size(); i++)
         {
            mydatastore->setAverage(product_results[i]);
            //std::cout<<product_results[i]->average_rating<<std::endl;
         }
         mergeSort(product_results, r);
         for(unsigned int i=0; i<product_results.size(); i++)
         {
            results->addItem(QString::fromStdString(product_results[i]->displayString()));
         }
      }
        
   }
   
}

void MainWindow::select_user_combo(const QString &text)
{
	std::set<User*> temp=mydatastore->get_user_set();
	std::set<User*>::iterator it;
	for(it=temp.begin();it!=temp.end();++it)
	{
	   if(text == QString::fromStdString((*it)->getName()))
	   {
	      current=*it;
	      current_user->setText(QString::fromStdString((current)->getName())); 
	      current_balance->setText(QString::number((current)->getBalance())); 
	   }
	}
	
   //current_user->setText(QString::fromStdString((current)->getName())); 
   if(view_cart_widget->isVisible())
   {
      view_user_cart();
   }

}

void MainWindow::select_user_button()
{
   if(user_select->text().isEmpty())
   {
      QMessageBox::information(this, "Invalid Username", "Please enter a valid username");
      return;
   }
   else
   {
      std::string text = user_select->text().toStdString();
      std::set<User*> temp=mydatastore->get_user_set();
	   std::set<User*>::iterator it;
	   bool found=false;
	   for(it=temp.begin();it!=temp.end();++it)
	   {
	      if(text == (*it)->getName())
	      {
	         current=*it;
	         current_user->setText(QString::fromStdString((current)->getName()));
	         current_balance->setText(QString::number((current)->getBalance())); 
	         int index = user_combo->findText(QString::fromStdString((current)->getName()));
	         user_combo->setCurrentIndex(index);
	         found=true;
	         break;
	      }
	   }
	   
	   if(found==false)
	   {
	      QMessageBox::information(this, "Invalid Username", "Please enter a valid username");
	   }
	   
	   if(view_cart_widget->isVisible())
      {
         view_user_cart();
      }     
   
   }

}

void MainWindow::add_product_to_cart()
{
   int size=product_results.size();
   if(product_results.size()>0 && current_product_index>=0 && current_product_index < size)
   {
      mydatastore->add_to_cart(current->getName(), product_results[current_product_index]); 
      current_cart=mydatastore->get_user_cart(current);
   
      if(view_cart_widget->isVisible())
      {
         view_user_cart();
      }
   }
   
   else
   {
      QMessageBox::information(this, "Invalid Product", "Please select a product to add to cart");
   }
   
   //search_product();
   //display_review(current_product_index);  
   //std::vector<Product*> temp = mydatastore->users_map[current->getName()];
   //std::cout<<temp.size()<<std::endl;
   
}

void MainWindow::view_user_cart()
{
   user_cart->clear();
   current_cart=mydatastore->get_user_cart(current);
   for(unsigned int i=0;i<current_cart.size();i++)
      {
         user_cart->addItem(QString::fromStdString
         (current_cart[i]->displayString()));
      }
   view_cart_widget->show();  
}

void MainWindow::buy_user_cart()
{
   if(current_cart.size()!=0)
   {
      mydatastore->buy_cart(current->getName()); 
      view_user_cart();
      search_product();
      current_balance->setText(QString::number((current)->getBalance())); 
   }
   else
   {
      QMessageBox::information(this, "Invalid Cart", "Cart is empty");
   }
   
}

void MainWindow::cart_index_select(int index)
{
   current_cart_index=index;
}
void  MainWindow::remove_from_cart()
{
   if(current_cart_index >= 0)
   {
      mydatastore->remove_from_cart(current->getName(), current_cart[current_cart_index]);
      if(view_cart_widget->isVisible())
      {
         view_user_cart();
      }
   }
   else
   {
      QMessageBox::information(this, "Invalid Product", "Please select a product to remove");
   }
   
}

void MainWindow::display_review(int index)
{
   if(index>=0)
   {
      current_product_index=index;
      current_reviews.clear();
      reviews->clear();
      std::set<Review*> temp = mydatastore->get_product_review(product_results[index]);
      std::set<Review*>::iterator it;
      for(it=temp.begin();it!=temp.end();++it)
      {
         current_reviews.push_back(*it);   
      }
   
      for(unsigned int i=0;i<current_reviews.size();i++)
      {
         reviews->addItem(QString::fromStdString
         (mydatastore->display_review(current_reviews[i])));
      }
      
   }
}

void MainWindow::sort_reviews(int state)
{
   if(state && current_reviews.size()>0)
   {
      reviews->clear();
      ReviewComp r;
      mergeSort(current_reviews, r);
      for(unsigned int i=0; i<current_reviews.size(); i++)
      {
         reviews->addItem(QString::fromStdString
         (mydatastore->display_review(current_reviews[i])));
      }   
   }  
   else if(state==0 && current_reviews.size()>0)
   {
      display_review(current_product_index);
   }
   
}

void MainWindow::add_product_review_main()
{
   //std::cout<<current_product_index<<std::endl;
   if(current_product_index >= 0)
   {
      add_review_widget->show();
   }
   else
   {
      QMessageBox::information(this, "Invalid Product", "Please select a product to add a review");
   }
}

void MainWindow::add_product_review_window()
{
   if(current_product_index >= 0)
   {
      if(!review_text->toPlainText().isEmpty())  
      {    
         std::string product_name = product_results[current_product_index]->getName();
         std::string date = date_product_review();
         int rating = rating_product_review();
         std::string review_text = review_product_review();
         std::string username = current->getName();
         Review* review = new Review(product_name, rating, 
         username, date, review_text);
      
         //std::cout<<product_name<<std::endl;
         //std::cout<<username<<std::endl;
         //std::cout<<rating<<std::endl;
         //std::cout<<date<<std::endl;
         //std::cout<<review_text<<std::endl;

         mydatastore->addReview(review);
      
         this->display_review(current_product_index);
         
         add_review_widget->hide();
      }
      
      else
      {
         std::string product_name = (product_results[current_product_index]->getName());
         QString product_name_ = QString::fromStdString(product_name);
         QString error_msg = "Please enter your review for " + product_name_;
         QMessageBox::information(this, "Invalid Review", error_msg);
      }
      
   }  
   
   
}

void MainWindow::save_database()
{
   QString file = QFileDialog::getSaveFileName(); 
   std::string filename = file.toStdString(); 
   std::ofstream ofile(filename.c_str());
   mydatastore->dump(ofile);
   ofile.close();
   
}

void MainWindow::quit_program()
{
   QString current_username = (QString::fromStdString(current->getName()));
   QString message = "Thank you for shopping with us, " + current_username + "! We hope you had a pleasant shopping experience.";
   QMessageBox::information(this, "Thank You!", message);
   QApplication::exit();
}

std::string MainWindow::date_product_review()
{  
   QString year_ = year_combo->currentText();
   std::string year = year_.toStdString();
   QString month_ = month_combo->currentText();
   std::string month = month_.toStdString();
   QString day_ = day_combo->currentText();
   std::string day = day_.toStdString();
   
   std::string date = year + "-" + month + "-" + day;
   
   //std::cout<<date<<std::endl;
   
   return date;

}

int MainWindow::rating_product_review()
{  
   QString rating_ = rating_combo->currentText();
   std::string rating_str = rating_.toStdString();
   int rating;
   
   std::stringstream strm(rating_str);
   strm>>rating;
   
   return rating;
   

}

std::string MainWindow::review_product_review()
{  
   QString review_text_ = review_text->toPlainText();
   std::string review_text = review_text_.toStdString();
   
   return review_text;
   

}
