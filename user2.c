user2()
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
		"Name=username", "Value={UserName2}", ENDITEM, 
		"Name=password", "Value={Password2}", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=69", ENDITEM, 
		"Name=login.y", "Value=11", ENDITEM, 
		LAST);
	
	spisokUSer[1] = lr_eval_string("{UserName2}");
	spisokPassword[1] = lr_eval_string("{Password2}");
	
		lr_output_message("В теле user2");
		
	web_reg_find("Text=flightID",
		"SaveCount=Count2",	             
		LAST);
		
	web_reg_find("SaveCount=CountFirst2",
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
		
		lr_output_message("Number of Tickets of user2 is: %s",lr_eval_string("{Count2}"));
		lr_output_message("Number of FirstClass of user2 is: %s",lr_eval_string("{CountFirst2}"));
		lr_output_message("________________________________________________________________");
		
		z = lr_eval_string("{CountFirst2}");
		masFirst[1] = atoi(z);
		
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
