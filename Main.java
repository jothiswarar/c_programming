import java.applet.Applet	;
import java.awt.Graphics	;
import java.awt.*          	;
import java.awt.event.*  	;

public class Main extends Applet implements ActionListener,ItemListener
{
      TextField name,person,rent,checkin,checkout,contactno	;
      Choice                   place,star,room,hotel 				;
      Checkbox              a,b,c,d,e1      				      	;
      CheckboxGroup    cbg                                 			;
      private Button       Disp                                			;
      private TextArea   taDetails                           			;
      String                    strl,m,f,f1,f2                      			;
      public void init() 
     {
         Label namep          = new Label("Hotel Name  	:");
         namep.setBounds    (20,40,90,20)     	; 
         Label placep          = new Label("Place                	:");
         placep.setBounds     (20,70,90,20)    	;
         Label starp             = new Label("Star                  	:");
         starp.setBounds        (20,100,90,20)  	;
         Label personp        = new Label("Guest Name     	:");
         personp.setBounds   (20,130,90,20)	;
         Label checkinp          = new Label("Check In       	 	:");
         checkinp.setBounds   (20,160,90,20) 	;
         Label checkoutp        = new Label("Check out      		:");
         checkoutp.setBounds (20,190,90,20) 	;
         Label contactnop       = new Label("Contact Number	:");
         contactnop.setBounds(20,220,90,20) 	; 
         Label genderp            = new Label("Gender          		:");
         genderp.setBounds    (20,260,90,20) 	;
         Label roomp              = new Label("Room Type      		:");
         roomp.setBounds      (20,310,90,20) 	;
         Label foodp               = new Label("Foods Needed   		:");
         foodp.setBounds       (20,350,90,20) 	;
         Label rentp                = new Label("Room Rent      		:");
         rentp.setBounds        (20,490,90,20) 	;
         hotel                          = new Choice()	;
         hotel.setBounds        (200,35,100,20)	;
         hotel.add("Hotel Novotel            ");
         hotel.add("Taj Deccan               	");
         hotel.add("Le Meridian            	");
         hotel.add("The Deltin               	");
         hotel.add("Park Plaza               	");
         hotel.add("Royal Orchid Resort 	");
         hotel.add("Fortune Landmark    	");
         hotel.add("Chancery Pavilion    	");
         place                      = new Choice();
         place.setBounds      (200,70,100,20);
         place.add("Chennai       	");
         place.add("Coimbatore 	");
         place.add("Madurai      	");
         place.add("Banglore     	");
         place.add("Tiruppur      	");
         place.add("Mercara       	");
         place.add("Ooty            	");
         place.add("Kodaikanal  	");
         star                    	= new Choice();
         star.setBounds     	(200,100,100,20);
         star.add("3 Star...")            ;
         star.add("5 Star...")            ;
         person            = new TextField()       	;
         person.setBounds    (200,130,100,20)	;
         checkin           = new TextField()        	;
         checkin.setBounds   (200,160,100,20)	;
         checkout          = new TextField()       	;
         checkout.setBounds  (200,190,100,20)	;
         contactno         = new TextField()       	;
         contactno.setBounds (200,220,100,20)	;
         a = new Checkbox("Male ",cbg, true)	;
         a.setBounds         (200,270,100,20)    	;
         b = new Checkbox("Female",cbg,false);
         b.setBounds         (300,270,100,20)    	;
         room     = new Choice()                        	   ;
         room.setBounds      (200,300,100,20)   	   ; 
         room.add("Single A/C                      	");
         room.add("Single Non A/C              	");
         room.add("Double A/C                     	");
         room.add("Double Non A/C             	");
         room.add("Triple A/C                       	");
         room.add("Triple Non A/C               	");
         room.add("Deluxe A/C                     	");
         room.add("Deluxe Non A/C             	");
         room.add("Standard Suite Room      	");
         room.add("Presidential Suite Room 	");
         room.add("Family A/C                     	");
         room.add("Family Non A/C             	");
         c             = new Checkbox("BreakFast 	");
         c.setBounds         (200,350,100,20)      	   ;
         d             = new Checkbox("Lunch      	");
         d.setBounds         (200,380,100,20)     	   ;
         e1           = new Checkbox("Dinner     	");
         e1.setBounds        (200,410,100,20)    	   ;
         rent         = new TextField()                  	   ;
         rent.setBounds      (200,490,100,20)    	   ;
         Disp       = new Button("Submit")       	   ;
         Disp.setBounds      (100,520,100,30)   	   ;
         taDetails = new TextArea(200,300)     	   ;
         taDetails.setBounds (450,50,300,400);
         add (namep)      	;
         add (hotel)          	;
         add (placep)        	;
         add (place)          	;
         add (starp)           	;
         add (star)             	;
         add (personp)      	;
         add (person)        	;
         add (checkinp)    	;
         add (checkin)      	;
         add (checkoutp)  	;
         add (checkout)    	;
         add (contactnop) 	;
         add (contactno)   	;
         add (genderp)      	;
         add (a)                 	;
         add (b)                 	;
         add (roomp)        	;
         add (room)          	;
         add (foodp)         	;
         add (c)                 	;
         add (d)                	;
         add (e1)         	;
         add (rentp)         	;   
         add (rent)           	;
         add (Disp)          	;
         add (taDetails)   	;
         hotel.addItemListener 		(this);
         place.addItemListener            	(this);
         star.addItemListener              	(this);
         checkin.addActionListener     	(this);
         checkout.addActionListener  	(this);
         contactno.addActionListener  	(this);
         a.addItemListener          		(this);
         b.addItemListener          		(this);
         room.addItemListener       	(this);
         c.addItemListener          		(this);
         d.addItemListener          		(this);
         e1.addItemListener         		(this);
         rent.addActionListener     		(this);
         Disp.addActionListener     	(this);
         setSize (520,520)	;
         setLayout  (null)	;
         setVisible (true)	;
     }
     public void paint(Graphics g)
     {
         g.setFont(new Font("Gabriola",Font.BOLD,25	 ));
         g.drawString      ("HOTEL MANAGEMENT",320,40);
     }
     public void itemStateChanged(ItemEvent e)
     {
         if(a.getLabel()=="Male")
         {
             m="       Male"	;
         }
         else
         {
             m="     Female"	;
         }
         if(c.getState()==true)
         {
             f=  "BreakFast"	;
         }
         if(d.getState()==true)
         {
             f1= "    Lunch"	;
         }
         if(e1.getState()==true)
         {
             f2= "   Dinner"	;
         }
       
    }
     public void actionPerformed(ActionEvent ae)
     {
         if(ae.getSource()==Disp)
         {
             strl="Name     			: "+hotel.getSelectedItem()+	"\n";
             strl+="Place               		: "+place.getSelectedItem()+	"\n";
             strl+="Star                		: "+star.getSelectedItem()+ 	"\n";
             strl+="Person Name    		: "+person.getText()+       	"\n";
             strl+="Date of Checking In 	: "+checkin.getText()+      	"\n";
             strl+="Date of Checking Out	: "+checkout.getText()+     	"\n";
             strl+="Contact Number      	: "+contactno.getText()+    	"\n";
             strl+="Gender              		: "+m+                      		"\n";
             strl+="FoodsNeeded         	: "+f+f1+f2+                		"\n";
             strl+="Room Rent           	: "+rent.getText()+         		"\n";
             taDetails.setText(strl)                                    		      ;
         }
     }
}
