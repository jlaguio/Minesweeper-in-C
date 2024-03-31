/**
 * @ Author: MMMM
 * @ Create Time: 2024-02-25 15:06:24
 * @ Modified time: 2024-03-31 16:51:52
 * @ Description:
 * 
 * This file defines the page handler for the login.
 */

#ifndef PAGE_LOGIN_
#define PAGE_LOGIN_

#include "../game/profile.game.c"
#include "../game/stats.game.c"

#include "../utils/utils.asset.h"
#include "../utils/utils.page.h"
#include "../utils/utils.component.h"

#include <string.h>

/**
 * Configures the logjn page.
 * 
 * @param   { p_obj }   pArgs_Page  The instance page we need to configure.
*/
void PageHandler_login(p_obj pArgs_Page) {
  
  Page *this = (Page *) pArgs_Page;
  Profile *pProfile = (Profile *) this->pSharedObject;
  int dWidth, dHeight, dMargin;

  // Header details
  char *sHeader = "profile login";
  char *sHeaderFont = "body-font";
  char sHeaderKey[STRING_KEY_MAX_LENGTH];

  // Component names
  char *sLoginComponent = "login.fixed";
  char *sLoginFormComponent = "login-form.col";
  char *sHeaderComponent = "header.acenter-x.atop-y";
  char *sFieldContainerComponent = "field-container.col.aleft-x.atop-y";
  char *sUsernamePromptComponent = "username-prompt.aleft-x";
  char *sPasswordPromptComponent = "password-prompt.aleft-x";
  char *sUsernameComponent = "username.aleft-x";
  char *sPasswordComponent = "password.aleft-x";
  char *sFieldPromptComponent = "field-prompt.aleft-x";
  char *sErrorPromptComponent = "error-prompt.aleft-x";
  char *sPopupComponent = "popup.fixed";

  // Input fields
  char *sUsernameField;
  char *sPasswordField;
  char cLoginCurrentField = 0;
  char cLoginFieldCount = 2;
  char cKeyPressed = 0;

  // Do stuff based on page status
  switch(this->ePageStatus) {

    case PAGE_ACTIVE_INIT:

      // Get the dimensions 
      dWidth = IO_getWidth();
      dHeight = IO_getHeight();
      dMargin = 46;

      // Create the header
      String_keyAndStr(sHeaderKey, sHeaderFont, sHeader);
      AssetManager_createTextAsset(this->pSharedAssetManager, sHeader, sHeaderFont);

      // Create component tree
      Page_addComponentContext(this, sLoginComponent, "root", 0, 0, dWidth, dHeight, "primary", "secondary");
      Page_addComponentContainer(this, sLoginFormComponent, sLoginComponent, 0, 0);
      Page_addComponentAsset(this, sHeaderComponent, sLoginFormComponent, dWidth / 2, 6, "", "", sHeaderKey);
      Page_addComponentContainer(this, sFieldContainerComponent, sLoginFormComponent, dWidth / 2 - dMargin / 2, 4);
      Page_addComponentText(this, sUsernamePromptComponent, sFieldContainerComponent, 1, 0, "", "", "Enter username:");
      Page_addComponentText(this, sUsernameComponent, sFieldContainerComponent, 1, 0, "", "", "");
      Page_addComponentText(this, sPasswordPromptComponent, sFieldContainerComponent, 1, 1, "", "", "Enter password:");
      Page_addComponentText(this, sPasswordComponent, sFieldContainerComponent, 1, 0, "", "", "");
      Page_addComponentText(this, sErrorPromptComponent, sFieldContainerComponent, 1, 2, "secondary", "accent", "");
      Page_addComponentText(this, sFieldPromptComponent, sFieldContainerComponent, 1, 1, "primary-darken-0.5", "", "[tab]    to switch between fields\n[enter]  to submit\n[esc]    to delete a profile");      
      Page_addComponentPopup(this, sPopupComponent, dWidth / 2, dHeight / 2, 56, 14, "secondary", "accent", "", "", "");

      // Define initial user states
      if(Page_getUserState(this, "login-current-field") == -1) Page_setUserState(this, "login-current-field", cLoginCurrentField);
      if(Page_getUserState(this, "login-field-count") == -1) Page_setUserState(this, "login-field-count", cLoginFieldCount);
    break;

    case PAGE_ACTIVE_RUNNING:

      // Key handling
      cLoginCurrentField = Page_getUserState(this, "login-current-field");
      cLoginFieldCount = Page_getUserState(this, "login-field-count");
      cKeyPressed = EventStore_get(this->pSharedEventStore, "key-pressed");

      // Retrieve the user input 
      sUsernameField = String_toUpper(EventStore_getString(this->pSharedEventStore, "username-input"));
      sPasswordField = String_toUpper(EventStore_getString(this->pSharedEventStore, "password-input"));

      // There's a popup
      if(Page_getUserState(this, "is-popup")) {

        // Switch between options
        if(cKeyPressed == '\t') {
          Page_toggleComponentPopup(this, sPopupComponent, "secondary", "accent");

        // Submit popup
        } else if(cKeyPressed == '\n' || cKeyPressed == '\r') {
          Page_disableComponentPopup(this, sPopupComponent);

          // Switch between which popup is active
          switch(Page_getUserState(this, "popup-action")) {
            
            // Deleting a profile
            case 0:

              // Yes was selected
              if(Page_readComponentPopup(this, sPopupComponent) == 0) {
              
                // If successful
                if(Profile_delete(pProfile, sUsernameField)) {
                  EventStore_clearString(this->pSharedEventStore, "username-input");
                  EventStore_clearString(this->pSharedEventStore, "password-input");
                  Page_setComponentText(this, sErrorPromptComponent, "Success: profile deleted.");

                // Not successful
                } else {
                  Page_setComponentText(this, sErrorPromptComponent, Profile_getErrorMessage(pProfile));
                }
              }
            break;
            
            // Creating a new profile
            case 1:

              // Yes was selected
              if(Page_readComponentPopup(this, sPopupComponent) == 0) {

                // Check if success
                if(Profile_register(pProfile, sUsernameField, sPasswordField)) {
                  EventStore_clearString(this->pSharedEventStore, "username-input");
                  EventStore_clearString(this->pSharedEventStore, "password-input");
                  Page_setComponentText(this, sErrorPromptComponent, "Success: profile created.");

                // Otherwise, display new error
                } else {
                  Page_setComponentText(this, sErrorPromptComponent, Profile_getErrorMessage(pProfile));
                }
              }
            break;
          }
        }

      // Proceed with other input handling
      } else {

        // Switch based on what key was last pressed
        switch(cKeyPressed) {

          // Switch fields
          case '\t':
            Page_setUserState(this, "login-current-field", ((int) cLoginCurrentField + 1) % (int) cLoginFieldCount);
          break;

          // Do input checking, then go to menu if successful
          case '\n': case '\r': case 27:
            
            // Exits the program when inputting quit or exit
            if(!strcmp(sUsernameField, "QUIT") || !strcmp(sUsernameField, "quit") ||
              !strcmp(sUsernameField, "EXIT") || !strcmp(sUsernameField, "exit")) {
              EventStore_set(this->pSharedEventStore, "terminate", 'y');
            }
            
            // Some fields are empty
            if(!strlen(sUsernameField) ||
              !strlen(sPasswordField)) {
              Page_setComponentText(this, sErrorPromptComponent, "Error: some fields are empty.");
              
            // If successful
            } else {
              
              // Login was successful
              if(Profile_login(pProfile, sUsernameField, sPasswordField)) {
                
                // Deleting account tho
                if(cKeyPressed == 27) {
                  Page_enableComponentPopup(this, sPopupComponent);
                  Page_setComponentPopupText(this, sPopupComponent, "Are.you.sure.you.want.to.delete.the.profile?\nThis.action.cannot.be.undone.");
                  Page_setComponentPopupOptions(this, sPopupComponent, "yes", "no.", "secondary", "accent");
                  Page_setUserState(this, "popup-action", 0);
                  
                  // Clear error
                  Profile_setErrorId(pProfile, PROFILE_ERROR_NONE);

                // Logging in
                } else {

                  // Read the profile data
                  Stats_readProfile(pProfile);

                  Page_idle(this);
                  Page_setNext(this, "menu");
                }
              
              // Login was NOT successful
              } else {
                Page_setComponentText(this, sErrorPromptComponent, Profile_getErrorMessage(pProfile));

                // Create a new account perhaps?
                if(Profile_getErrorId(pProfile) == PROFILE_ERROR_NOT_FOUND && cKeyPressed != 27) {
                  Page_enableComponentPopup(this, sPopupComponent);
                  Page_setComponentPopupText(this, sPopupComponent, "This.account.does.not.yet.exist.\nWould.you.like.to.register.it?");
                  Page_setComponentPopupOptions(this, sPopupComponent, "yes", "no.", "secondary", "accent");
                  Page_setUserState(this, "popup-action", 1);
                }
              }
            }

          break;

          default:
          
            // Update the values of the current inputted username
            if(cLoginCurrentField == 0) { 
              EventStore_setString(this->pSharedEventStore, "key-pressed", "username-input");

              Page_setComponentColor(this, sUsernamePromptComponent, "primary", "");
              Page_setComponentColor(this, sUsernameComponent, "accent", "");
              Page_setComponentColor(this, sPasswordPromptComponent, "primary-darken-0.75", "");
              Page_setComponentColor(this, sPasswordComponent, "primary-darken-0.75", "");

            // Update the values of the current inputted password
            } else if(cLoginCurrentField == 1) {
              EventStore_setString(this->pSharedEventStore, "key-pressed", "password-input");      

              Page_setComponentColor(this, sUsernamePromptComponent, "primary-darken-0.75", "");
              Page_setComponentColor(this, sUsernameComponent, "primary-darken-0.75", "");
              Page_setComponentColor(this, sPasswordPromptComponent, "primary", "");
              Page_setComponentColor(this, sPasswordComponent, "accent", "");          
            }

            // Clear the error
            if(cKeyPressed)
              Page_setComponentText(this, sErrorPromptComponent, "");

          break;
        }
      }

      // Indicate the user input on screen
      Page_setComponentText(this, sUsernameComponent, strlen(sUsernameField) ? sUsernameField : "<USERNAME>");
      Page_setComponentText(this, sPasswordComponent, strlen(sPasswordField) ? sPasswordField : "<PASSWORD>");

    break;

    default: break;
  }
}

#endif