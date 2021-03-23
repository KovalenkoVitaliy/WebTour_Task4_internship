user1()
{
	web_reg_save_param_ex(
		"ParamName=CompSession1",
		"LB=userSession\" value=\"",
		"RB=\"/>",
		"Ordinal=1",
		SEARCH_FILTERS,
		LAST);
	
	web_url("Webtours",
		"URL=http://localhost:1080/Webtours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);


	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value={CompSession1}", ENDITEM, 
		"Name=username", "Value={UserName1}", ENDITEM, 
		"Name=password", "Value={Password1}", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=69", ENDITEM, 
		"Name=login.y", "Value=11", ENDITEM, 
		LAST);
	
	spisokUSer[0] = lr_eval_string("{UserName1}");
	spisokPassword[0] = lr_eval_string("{Password1}");
	
		lr_output_message("В теле user1");
		
	web_reg_find("Text=flightID",
		"SaveCount=Count1",	             
		LAST);
		
	web_reg_find("SaveCount=CountFirst1",
		"Text=First",
		LAST);
	
	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
		
		lr_output_message("Number of Tickets of user1 is: %s",lr_eval_string("{Count1}"));
		lr_output_message("Number of FirstClass of user1 is: %s",lr_eval_string("{CountFirst1}"));
		lr_output_message("________________________________________________________________");
		
		z = lr_eval_string("{CountFirst1}");
		masFirst[0] = atoi(z);
		
	web_url("SignOff Button",
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);
	
	
	return 0;
}
