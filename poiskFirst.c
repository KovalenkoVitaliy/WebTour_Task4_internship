poiskFirst()
{
	
	max = masFirst[0];
			
		for(j=0; j<3; j++) {
				
			if (masFirst[j] >= max) {
					
				max = masFirst[j];
					
				NumForDelete = (j);
				
			}
			
		}
			
		lr_save_int(max, "MAX");
		lr_output_message("Max count of First class is: %s",lr_eval_string("{MAX}"));
		lr_save_int(NumForDelete, "NumberForDelete");
		lr_output_message("Number user for delete ticket is: %s",lr_eval_string("{NumberForDelete}"));
		lr_save_string(spisokUSer[NumForDelete], "UserDeletete");
		lr_save_string(spisokPassword[NumForDelete], "PasswordDeletete");
		lr_output_message("________________________________________________________________");
		
		
	
	return 0;
}
