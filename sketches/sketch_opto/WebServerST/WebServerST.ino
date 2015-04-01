
<!-- saved from url=(0070)http://playground.arduino.cc/Code/WebServerST?action=sourceblock&num=1 -->
<html><head><meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1"><style type="text/css"></style><style id="clearly_highlighting_css" type="text/css">/* selection */ html.clearly_highlighting_enabled ::-moz-selection { background: rgba(246, 238, 150, 0.99); } html.clearly_highlighting_enabled ::selection { background: rgba(246, 238, 150, 0.99); } /* cursor */ html.clearly_highlighting_enabled {    /* cursor and hot-spot position -- requires a default cursor, after the URL one */    cursor: url("chrome-extension://pioclpoplcdbaefihamjohnefbikjilc/clearly/images/highlight--cursor.png") 14 16, text; } /* highlight tag */ em.clearly_highlight_element {    font-style: inherit !important; font-weight: inherit !important;    background-image: url("chrome-extension://pioclpoplcdbaefihamjohnefbikjilc/clearly/images/highlight--yellow.png");    background-repeat: repeat-x; background-position: top left; background-size: 100% 100%; } /* the delete-buttons are positioned relative to this */ em.clearly_highlight_element.clearly_highlight_first { position: relative; } /* delete buttons */ em.clearly_highlight_element a.clearly_highlight_delete_element {    display: none; cursor: pointer;    padding: 0; margin: 0; line-height: 0;    position: absolute; width: 34px; height: 34px; left: -17px; top: -17px;    background-image: url("chrome-extension://pioclpoplcdbaefihamjohnefbikjilc/clearly/images/highlight--delete-sprite.png"); background-repeat: no-repeat; background-position: 0px 0px; } em.clearly_highlight_element a.clearly_highlight_delete_element:hover { background-position: -34px 0px; } /* retina */ @media (min--moz-device-pixel-ratio: 2), (-webkit-min-device-pixel-ratio: 2), (min-device-pixel-ratio: 2) {    em.clearly_highlight_element { background-image: url("chrome-extension://pioclpoplcdbaefihamjohnefbikjilc/clearly/images/highlight--yellow@2x.png"); }    em.clearly_highlight_element a.clearly_highlight_delete_element { background-image: url("chrome-extension://pioclpoplcdbaefihamjohnefbikjilc/clearly/images/highlight--delete-sprite@2x.png"); background-size: 68px 34px; } } </style><style type="text/css"></style><style>[touch-action="none"]{ -ms-touch-action: none; touch-action: none; }[touch-action="pan-x"]{ -ms-touch-action: pan-x; touch-action: pan-x; }[touch-action="pan-y"]{ -ms-touch-action: pan-y; touch-action: pan-y; }[touch-action="scroll"],[touch-action="pan-x pan-y"],[touch-action="pan-y pan-x"]{ -ms-touch-action: pan-x pan-y; touch-action: pan-x pan-y; }</style><style type="text/css">
    .fm-clr {
        clear: both;
    }

    div.fm-base-content {
        display: none;
    }

    .fm-container {
        font-family: Helvetica, Arial, sans-serif !important;
        font-size: 10pt;
        line-height: 1.3;
        color: black;
        font-weight: normal;
        text-shadow: none;
        text-align: left;
        background-color: #fff;
    }
    .fm-container * {
        font-size: 10pt;
        font-family: Helvetica, Arial, sans-serif !important;
        font-weight: normal;
        padding: 0;
        margin: 0;
        line-height: normal;
        -webkit-margin-before: 0;
        -webkit-margin-after: 0;
        -webkit-margin-start: 0;
        -webkit-margin-end: 0;
        -webkit-padding-start: 0;
        -webkit-box-shadow: none;
        -moz-box-shadow: none;
        box-shadow: none;
        transition: none;
        -webkit-transition: none;
        -moz-transition: none;
    }
    .fm-container input {
        background-color: #fff;
        width: auto;
        display: inline;
    }
    .fm-container select {
        height: auto;
        width: auto;
    }
    .fm-container label {
        display: inline;
        text-align: left;
    }

    .fm-container a {
        color: #08c !important;
        text-decoration: none;
    }

    .fm-container a:hover {
        color: #005487 !important;
        text-decoration: underline;
        background-color: transparent;
    }

    .fm-container a.fm-btn {
        padding: 6px 8px;
        background-color: #f7f7f7;
        border: 1px dashed #cfcfcf;
        border-radius: 5px;
        -webkit-border-radius: 5px;
        -moz-border-radius: 5px;
    }
    .fm-container a.fm-btn.primary {
        background-color: #f4f9fd;
        border: 1px dashed #c6def6;
    }
    .fm-container a.fm-btn:hover {
        border-style: solid;
    }

    div#fm_search_field_wrapper {
        position: relative;
    }
    input#fm_search_field {
        width: 230px;
        background: url('https://plus.im/static/img/search.png') 
            no-repeat scroll left 0 transparent;
        height: 16px;
        font-size: 12px;
        margin-left: 0px;
        margin-bottom: 0px;
        border-bottom: 1px solid #cfcfcf;
        border-right: 0;
        border-left: 0;
        border-top: 0;
        line-height: 16px;
    }

    input#fm_search_field[placeholder] {
        padding-left: 14px;
    }

    div#fm_search_field_close {
        width: 10px;
        height: 10px;
        background: url('https://plus.im/static/img/close_on.png') -4px -4px;
        right: 6px;
        top: 3px;
        position: absolute;
        display: none;
    }

    #fm_base_resizer {
        background-color: #E0E0E0;
        height: 3px; 
        cursor: n-resize;
    }
    #fm_base_resizer:hover {
        background-color: #eee;
        height: 3px; 
        cursor: n-resize;
    }

    div#fm_header {
        background-color: #E0E0E0;
        overflow: hidden;

        font-family: Helvetica, Arial, sans-serif;
        height: 26px;
        font-size: 10pt;
        line-height: 16pt;
        color: #646464;
        text-shadow: none;
        border-bottom: 1px solid #cfcfcf;
    }

    div#fm_header:hover {
        background-color: #eaeaea;
    }

    div#fm_header.connected {
        background-color: #DBFFC7;
    }

    div#fm_header.inprogress {
        background: #E0E0E0 url('https://plus.im/static/img/load.gif') 2px center no-repeat;
        padding-left: 20px;
    }

    div#fm_header_title {
        overflow: hidden;
        white-space: nowrap;
        padding: 2px 2px 2px 4px;
        line-height: 22px;
        font-weight: bold;
        cursor: pointer;
    }

    #fm_minimize_btn {
        display: none;
    }
    #fm_settings_btn, #fm_minimize_btn, #fm_back_btn, 
    #fm_close_main_btn, #fm_slide_down_btn, #fm_slide_up_btn {
        border: 0;
        float: right;
        height: 20px;
        width: 20px;
        padding: 0px 4px;
        margin: 2px 2px;
        cursor: pointer;
    }
    #fm_settings_btn:hover {
        opacity: 0.7;
        filter: alpha(opacity=70);
    }
    #fm_settings_btn:hover, #fm_minimize_btn:hover, #fm_back_btn:hover, 
    #fm_close_main_btn:hover, #fm_slide_down_btn:hover, #fm_slide_up_btn:hover {
        opacity: 1;
        filter: alpha(opacity=100);
        background-color: #fff;
        border-radius: 3px;
        -webkit-border-radius: 3px;
        -moz-border-radius: 3px;
    }

    #fm_back_btn {
        display: none;
        width: auto;
        font-size: 14px;
    }

    div.fm-infomsg {
        font-style: italic;
    }

    /*chatcss*/
    div.fm-chatm {
        max-height: 265px;
        min-height: 60px;
        overflow-x: hidden;
        overflow-y: auto;
    }

    div.fm-chatm.loading {
        background: #E0E0E0 url('https://plus.im/static/img/load.gif') center center no-repeat;
    }

    div.fm-chatm-emptylist {
        padding: 20px;
        color: #ccc;
        text-align: center;
    }

    div.fm-chatm.multi { /* multichats */
        /*width: 170px;
        border-right: 1px solid #e0e0e0;*/
    }
    div.fm-chatp { /* multichats */
        /*width: 70px;
        float: right;*/

        border-bottom: 1px solid #e0e0e0;
        overflow: hidden;
    }
    div.fm-chatp div.fm-part-nick, div.fm-chatp div.fm-part-extra {
        max-width: 80px;
        float: left;
        white-space: nowrap;
        margin: 2px 5px 2px 2px;
        padding-right: 4px;

        background-color: #C1D2F3;
        border-radius: 7px;
        -webkit-border-radius: 7px;
        -moz-border-radius: 7px;

        overflow: hidden;
        text-overflow: ellipsis;
        -o-text-overflow: ellipsis;
        -webkit-text-overflow: ellipsis;
    }
    div.fm-chatp div.fm-part-extra { /* overriding bgcolor from above */
        background-color: #fff;
    }

    div.fm-chathb {
        background-color: #f7f7f7;
        border-bottom: 1px solid #D0D0D0;
        padding: 1px 0 1px 5px;
    }

    div.fm-chat-headclose {
        margin: 5px 5px 0 0;
        width: 14px;
        height: 15px;
        background: url('https://plus.im/static/img/close_dialog.png');
        float: right;
        cursor: pointer;
    }
    div.fm-chat-headclose:hover {
        background: url('https://plus.im/static/img/close_dialog.png');
        opacity: 0.7;
        filter: alpha(opacity=70);
    }
    div.fm-chat-headnick, div.fm-upload-indicator {
        float: left;
        width: 80%;
        overflow: hidden;
        white-space: nowrap;
        padding: 2px 2px 2px 4px;
        font-weight: bold;
        line-height: 22px;
        cursor: pointer;
    }
    div.fm-chat-header {
        background-color: #e0e0e0;
        overflow: hidden;
        height: 25px;
        line-height: 16pt;
        font-family: Helvetica, Arial, sans-serif;
        color: #646464;
        border-bottom: 1px solid #D0D0D0;
        border-top: 2px solid #e0e0e0;
        border-left: 2px solid #e0e0e0;
        border-right: 2px solid #e0e0e0;
        border-top-left-radius: 3px;
        border-top-right-radius: 3px;
        -webkit-top-left-radius: 3px;
        -webkit-top-right-radius: 3px;
        -moz-border-radius-topleft: 3px;
        -moz-border-radius-topright: 3px;
    }
    div.fm-chat-header:hover {
        background-color: #eaeaea;
        border-top: 2px solid #eaeaea;
        border-left: 2px solid #eaeaea;
        border-right: 2px solid #eaeaea;
    }
    div.fm-chat-header.fm-has-newmsg {
        background-color: #fee676;
        border-top: 2px solid #fee676;
        border-left: 2px solid #fee676;
        border-right: 2px solid #fee676;
    }

    div#fm_chats {
        margin-top: 1px;
        overflow: auto;
        height: 242px;
        width: 245px;
    }
    div.fm-chatw {
        background-color: #fff;
        min-width: 200px;
        width: 300px;

        bottom: 0px;
        position: fixed;
        z-index: 10000;
        border-radius: 3px;
        -webkit-border-radius: 3px;
        -moz-border-radius: 3px;

        -moz-box-shadow: 0 0 5px #555;
        -webkit-box-shadow: 0 0 5px #555;
        box-shadow: 0 0 5px #555;
    }
    div.fm-chatw.fm-has-newmsg {
        
    }

    div.fm-chat-btns {
        padding-left: 5px;
        background-color: #F2F2F2;
        border-top: 1px solid #D0D0D0;
    }

    div.fm-chat-btns > div {
        margin-top: 1px;
        margin-bottom: 1px;
    }

    div.fm-share-btn {
        background-image: url('https://plus.im/static/img/chat-toolbar/im_plus_ok.png');
        float: left;
        width: 25px;
        height: 23px;
    }

    div.fm-share-btn:hover {
        background-image: url('https://plus.im/static/img/chat-toolbar/im_plus_ok_over.png');
    }

    div.fm-smiley-btn {
        float: left;
        width: 25px;
        height: 23px;
        background-image: url('https://plus.im/static/img/chat-toolbar/add_smile.png');
    }

    div.fm-smiley-btn:hover {
        background-image: url('https://plus.im/static/img/chat-toolbar/add_smile_over.png');
    }

    div#fm_smiley_panel {
        width: 154px;
        height: 44px;
        display: none;
        background-color: #F2F2F2;
        position: absolute;
        z-index: 10000;
        border-width: 5px;
        border-style: solid;
        border-color: #E4E6E8;
        border-top-left-radius: 3px;
        border-top-right-radius: 3px;
        border-bottom-right-radius: 3px;
        border-bottom-left-radius: 3px;
    }

    div.fm-smile-clickable {
        float: left;
        width: 22px;
        height: 22px;
    }

    div.fm-smile-clickable > img {
        padding: 3px;
    }

    div.fm-smile-clickable:hover {
        background-color: #E4E6E8;
    }

    div.fm-upload-btn {
        float: left;
        width: 27px;
        height: 23px;
        background-image: url('https://plus.im/static/img/chat-toolbar/send_picture.png');
    }

    div.fm-upload-btn:hover {
        background-image: url('https://plus.im/static/img/chat-toolbar/send_picture_over.png');
    }



    div.fm-chat-input {
        padding: 0px 5px 2px 4px;
        background-color: #F2F2F2;
        border-bottom: 2px solid #f2f2f2;
        border-left: 2px solid #f2f2f2;
        border-right: 2px solid #f2f2f2;
        border-bottom-right-radius: 3px;
        border-bottom-left-radius: 3px;
        -webkit-bottom-right-radius: 3px;
        -webkit-bottom-left-radius: 3px;
        -moz-border-radius-bottomright: 3px;
        -moz-border-radius-bottomleft: 3px;
    }

    div.fm-chat-input textarea {
        border-radius: 3px;
        -webkit-border-radius: 3px;
        -moz-border-radius: 3px;
        border: 1px solid silver;
        height: 22px;
        max-height: 300px;
        width: 286px;
        max-width: 286px;
        background: #fff;
        display: inline;
        -moz-box-sizing: inherit;
    }

    img.fm-upload-btn {
        vertical-align: top;
        display: inline;
    }

    div.fm-message:first-child {
        margin-top: 5px;
    }

    div.fm-message:last-child {
        margin-bottom: 5px;
    }

    div.fm-message {
        padding: 0 5px;
        word-wrap: break-word;
    }

    div.fm-message.fm-dir-IN {
        background-color: #F0F6FA;
        padding-top: 1px;
        padding-bottom: 1px;
    }

    span.fm-message-nick-green {
        color: #79a51b;
    }

    span.fm-message-nick-blue {
        font-weight: bold;
        color: #3f8abe;
    }
    
    span.fm-message-time {
        float: right;
        color: grey;
        font-size: 10px;
        margin: 2px 0 0 2px;
    }

    div.fm-cle, div.fm-chatli {
        height: 29px;
        overflow: hidden;
        border-bottom: 1px solid #f7f7f7;
        margin-bottom: 1px;
        cursor: pointer;
    }
    div.fm-cle.fm-has-newmsg, div.fm-chatli.fm-has-newmsg {
        background-color: #fee676;
    }

    div.fm-cle.picked {
        background-color: #f7f7f7;
    }

    div.fm-cle.expanded {
        height: 50px;
        background-color: #f7f7f7;
    }

    div.fm-cle:hover, div.fm-chatli:hover {
        background-color: #f7f7f7;
    }

    div.fm-cle-cmds {
        clear: both; 
        padding: 3px;
        margin-right: 9px;
        float: right;
    }
    a.fm-cle-cmd {
        font-size: 8.5pt;
    }
    span.fm-light-sep {
        color: #bbb;
    }

    div.fm-cle-ava {
        float: left;
        width: 28px;
        height: 28px;
    }

    div.fm-cle-ava > img {
        max-width: 28px;
        max-height: 28px;
    }

    div.fm-cle-st {
        height: 14px;
        width: 16px;
        float: left;
    }

    div.fm-chat-pin {
        height: 13px;
        width: 12px;
        float: left;
        margin: 1px 2px;
    }
    div.fm-pin-on {
        background:url('https://plus.im/static/img/star.png') center no-repeat;
    }
    div.fm-pin-off {
        background:url('https://plus.im/static/img/star-empty.png') center no-repeat;
    }

    div.fm-cle-tr {
        height: 16px;
        width: 28px;
        float: right;
        margin-top: 5px;
    }
    div.fm-cle:hover div.fm-cle-tr { /* when cle is hovered */
        background: url('https://plus.im/static/img/arr_down.png') center no-repeat !important;
    }
    div.fm-cle.expanded div.fm-cle-tr.expanded {
        background: url('https://plus.im/static/img/arr_up.png') center no-repeat !important;
    }

    div.fm-chatli:hover div.fm-cle-tr {
        background: url('https://plus.im/static/img/arr_down.png') center no-repeat !important;
    }
    div.fm-chatli.expanded div.fm-cle-tr.expanded {
        background: url('https://plus.im/static/img/arr_up.png') center no-repeat !important;
    }

    div.fm-cle-name, div.fm-cle-psm {
        width: 154px;
        float: left;
        overflow: hidden;
        white-space:nowrap;
        text-overflow: ellipsis;
        margin-top: 1px;
    }

    div.fm-cle-psm {
        color: #7A7A7A;
        margin-left: 16px;
        font-size: 10px;
    }

    div.fm-account {
        overflow: hidden;
        white-space: nowrap;
        margin-bottom: 3px;
        height: 20px;
    }

    div.fm-tr-icon {
        float: left;
        width: 20px;
        height: 16px;
    }   
    
    div.fm-account > .fm-rem-acc-btn {
        background: url('https://plus.im/static/img/trash.png') center no-repeat;
        cursor: pointer;
        width: 15px;
        height: 16px;
        float: right;
    }

    div.fm-account > .fm-rem-acc-btn:hover {
        background: url('https://plus.im/static/img/trash_on.png') center no-repeat;"
    }

    div.fm-account > .fm-edit-acc-btn {
        background: url('https://plus.im/static/img/edit_service.png') center no-repeat;
        cursor: pointer;
        width: 15px;
        height: 16px;
        float: right;
    }

    div.fm-account > .fm-edit-acc-btn:hover {
        background: url('https://plus.im/static/img/edit_service_on.png') center no-repeat;"
    }

    div.fm-account > label > input {
        margin-left: 3px;
    }

    div.fm-account > label > span {
        width: 77%;
        margin-left: 4px;
        display: inline-block;
        white-space: nowrap;
        overflow: hidden;
        text-overflow: ellipsis;
        -o-text-overflow: ellipsis;
        -webkit-text-overflow: ellipsis;
    }

    div.fm-account > label {
        float: left;
        width: 86%;
        max-width: 210px;
        white-space: nowrap;
    }

    div#fm_base {
        position:fixed;
        bottom: 0px;
        right: 3px;
        background-color: white;
        border: 2px solid #e0e0e0;
        width: 245px;
        z-index: 10000;
        height: auto;

        border-radius: 3px;
        -webkit-border-radius: 3px;
        -moz-border-radius: 3px;

        -moz-box-shadow: 0 0 5px #555;
        -webkit-box-shadow: 0 0 5px #555;
        box-shadow: 0 0 5px #555;
    }

    div#fm_microbase {
        display: none; 
        opacity: 0.7;
        filter: alpha(opacity=70);
        cursor: pointer;
        position: fixed; 
        bottom: 0; 
        right: 3px; 
        z-index: 900000;
        background: #eee url('https://plus.im/static/img/back_arrow.png') 
            center center no-repeat;
        height: 27px;
        width: 19px;
        border: 2px solid #e0e0e0;

        border-radius: 3px;
        -webkit-border-radius: 3px;
        -moz-border-radius: 3px;

        -moz-box-shadow: 0 0 5px #555;
        -webkit-box-shadow: 0 0 5px #555;
        box-shadow: 0 0 5px #555;
    }

    div#fm_microbase:hover {
        opacity: 1;
        filter: alpha(opacity=100);
    }

    div#fm_microbase.fm-has-newmsg {
        background-color: #fee676;
        border-top: 2px solid #fee676;
        border-left: 2px solid #fee676;
        border-right: 2px solid #fee676;
    }

    div#fm_settings_wrapper {
        padding: 10px;
        margin-bottom: 25px;
        display: none;
    }

    div#fm_accounts, div#fm_add_account, div#fm_add_contact {
        height: 300px;
        overflow: auto;
    }
    div#fm_body {
        height: 300px;
        overflow: hidden;
    }
    
    div#fm_accounts {
        display: none;
    }

    div#fm_account_list {
        margin: 10px 0px;
        overflow: auto;
        max-height: 200px;
    }

    a.fm-big-add-acc-btn {
        display: block;
        width: 80%;
        margin-left: 10%;
        text-align: center;
        padding: 5px 0 !important;
        background-color: #f4f9fd;
        border: 1px dashed #c6def6;
        border-radius: 3px;
        -webkit-border-radius: 3px;
        -moz-border-radius: 3px;
    }

    ul.fm-tabs-holder {
        overflow: visible;
        color: #646464;
        list-style:none;
        background-color: #f2f2f2;
        padding-top: 5px;
        border-bottom: 1px solid #cfcfcf;
    }
    ul.fm-tabs-holder li {
        float: left;
        padding: 2px 5px;
        border: 1px solid transparent;
        border-bottom: 1px solid #cfcfcf;
        margin-bottom: -1px;
        margin-left: 2px;
        cursor: pointer;
        width: auto;
        list-style-type: none;
    }
    ul.fm-tabs-holder li:hover {
        background-color: #f2f2f2; 
        border: 1px solid #cfcfcf;
        border-top-left-radius: 3px;
        border-top-right-radius: 3px;
        -webkit-top-left-border-radius: 3px;
        -webkit-top-right-border-radius: 3px;
        -moz-border-radius-topleft: 3px;
        -moz-border-radius-topright: 3px;
    }
    ul.fm-tabs-holder li.fm-active {
        background-color: #fff; 
        border: 1px solid #cfcfcf;
        border-bottom: 1px solid #fff !important;
        border-top-left-radius: 3px;
        border-top-right-radius: 3px;
        -webkit-top-left-border-radius: 3px;
        -webkit-top-right-border-radius: 3px;
        -moz-border-radius-topleft: 3px;
        -moz-border-radius-topright: 3px;
    }

    img#fm_add_contact_btn {
        cursor: pointer;
        border: 0;
        position: absolute; 
        top: 65px; 
        right: 7px;
    }
    img#fm_add_contact_btn:hover {
        opacity: 0.7;
        filter: alpha(opacity=70);
    }

    div#fm_add_contact select[name=account] {
        width: 225px;
        overflow: auto;
    }

    div#fm_add_contact input[name=cid], div#fm_add_contact input[name=nick] {
        width: 225px;
        height: 20px;
        border: 1px solid #cfcfcf;
        margin: 3px 0 10px 0;
    }

    div#fm_add_account {
        display: none;
        overflow: auto;
    }

    div#fm_add_account input[name=lgn], div#fm_add_account input[name=pwd],
    div#fm_add_account input[name=jbr_host], div#fm_add_account input[name=jbr_port] {
        width: 225px;
        height: 20px;
        border: 1px solid #cfcfcf;
        margin: 3px 0 10px 0;
    }

    div#fm_add_account input[name=jbr_host] {
        width: 170px;
    }

    div#fm_add_account input[name=jbr_port] {
        width: 40px;
    }

    div#fm_add_account div.fm-jabber-extended {
        display: none;
        padding: 10px 0 0 0;
    }

    img#fm_add_acc_selimg {
        vertical-align: top;
    }

    div#fm_search_cl {
        margin-top: 1px;
        overflow: auto;
        height: 221px;
        width: 245px;
        display: none;
    }

    div#fm_cl {
        margin-top: 1px;
        overflow: auto;
        height: 221px;
        width: 245px;
    }
    div#fm_cl.loading {
        background: #E0E0E0 url('https://plus.im/static/img/load.gif') center center no-repeat;
    }

    div.fm-cl-group-head {
        cursor: pointer;
        height: 25px;
        background-color: #f7f7f7;
        border-bottom: 1px solid white;
    }

    img.fm-cl-group-toggle {
        margin-left: 5px;
        float: left;
        padding-top: 2px;
    }

    div.fm-cl-group-title {
        margin-left: 30px;
        padding-left: 4px;
        padding-top: 5px;
    }

    div#fm_news {
        margin-top: 1px;
        overflow: auto;
        height: 238px;
        width: 245px;
    }
    div#fm_news .fm-newsli {
        border-bottom: 1px solid #f7f7f7;
        margin: 2px 2px 2px 2px;
        padding-bottom: 2px;
    }

    div#fm_my_profile {
        overflow: hidden;
        width: 239px;
        background-color: #f2f2f2;
        padding: 5px 3px 0 3px;
    }
    img#fm_my_avatar {
        max-width: 28px;
        max-height: 28px;
        float: left;
        margin: 1px 5px 1px 1px;
    }
    div.fm-custom-status {
        float: left;
        width: 186px;
        height: 21px;
        max-height: 21px;
        margin: 4px;
        font-size: 1.1em;
        line-height: 1.5em;
        padding-left: 20px;
        background: #eee url('https://plus.im/static/img/st/new2/onl.png') 
            5px center no-repeat;
        border: 1px solid #ccc;
        border-radius: 3px;
        -webkit-border-radius: 3px;
        -moz-border-radius: 3px;
        overflow: none;
        position: relative;
    }
    .fm-my-st-onl {
        background: url('https://plus.im/static/img/st/new2/onl.png') 10px center no-repeat;
    }
    .fm-my-st-awy {
        background: url('https://plus.im/static/img/st/new2/awy.png') 10px center no-repeat;
    }
    .fm-my-st-dnd {
        background: url('https://plus.im/static/img/st/new2/dnd.png') 10px center no-repeat;
    }
    .fm-my-st-na {
        background: url('https://plus.im/static/img/st/new2/na.png') 10px center no-repeat;
    }
    .fm-my-st-inv {
        background: url('https://plus.im/static/img/st/new2/inv.png') 10px center no-repeat;
    }
    select#fm_my_st {
        cursor: pointer;
        opacity: 0;
        filter: alpha(opacity=0);
        width: 40px;
        height: 18px;
        font-size: 12px;
        /*margin: 4px 2px;*/
        padding: 0;
        color: #555;
        border: 1px solid #ccc;
        border-radius: 3px;
        -webkit-border-radius: 3px;
        -moz-border-radius: 3px;
        z-index: 10;
        position: absolute;
        top: 0;
    }
    div#fm_my_st_fe {
        float: left;
        position: relative;
        cursor: pointer;
        width: 38px;
        height: 18px;
        font-size: 14px;
        margin: 4px 2px;
        padding: 0;
        color: #555;
        background-color: #fff;
        border: 1px solid #ccc;
        border-radius: 3px;
        -webkit-border-radius: 3px;
        -moz-border-radius: 3px;
    }
    input#fm_my_psm {
        float: left;
        width: 152px;
        height: 18px;
        font-size: 12px;
        margin: 4px 0px 4px 2px;
        padding: 0;
        color: #555;
        border: 1px solid #ccc;
        border-radius: 3px;
        -webkit-border-radius: 3px;
        -moz-border-radius: 3px;
    }

    div#fm_feedback_wrapper {
        position: absolute;
        left: 7px;
        bottom: 3px;
    }

    /* notif center */
    .fm-notif-center {
        position: fixed; 
        bottom: 330px; 
        right: 7px; 
        z-index: 11000; 
        color: black; 
        background: transparent;
    }
    .fm-notif-center.whencollapsed {
        bottom: 30px;
    }
    .fm-notif-center > .fm-notification {
        position: relative;
        list-style: none;
        font-size: 14px;
        background: #fafafa;
        padding: 5px;
        margin: 5px 0;
        border: 2px solid #ccc;
        border-radius: 3px;
        -webkit-border-radius: 3px;
        -moz-border-radius: 3px;
        min-height: 35px;
        width: 230px;
    }
    .fm-notif-center > .fm-newsbox {
        position: relative;
        list-style: none;
        font-size: 14px;
        background: #FCFCEB;
        padding: 5px;
        margin: 5px 0;
        border: 2px solid #ccc;
        border-radius: 3px;
        -webkit-border-radius: 3px;
        -moz-border-radius: 3px;
        min-height: 35px;
        width: 230px;
    }
    /*.fm-notif-center > .fm-newsbox a {
        text-decoration: none;
        color: #3F8ABE;
    }
    .fm-notif-center > .fm-newsbox a:hover {
        text-decoration: underline;
        color: #3F8ABE;
    }*/

    #fm_upload_form {
        display: none;
        position: fixed;
        bottom: 0; right: 0;
        height: 1px; width: 1px;
    }

    .fm-animated {
        -webkit-animation-fill-mode: both;
        -moz-animation-fill-mode: both;
        -ms-animation-fill-mode: both;
        -o-animation-fill-mode: both;
        animation-fill-mode: both;
        -webkit-animation-duration: 1s;
        -moz-animation-duration: 1s;
        -ms-animation-duration: 1s;
        -o-animation-duration: 1s;
        animation-duration: 1s;
    }

    .fm-animated.hinge {
        -webkit-animation-duration: 2s;
        -moz-animation-duration: 2s;
        -ms-animation-duration: 2s;
        -o-animation-duration: 2s;
        animation-duration: 2s;
    }

    @-webkit-keyframes tada {
        0% {-webkit-transform: scale(1);}   
        10%, 20% {-webkit-transform: scale(0.9) rotate(-3deg);}
        30%, 50%, 70%, 90% {-webkit-transform: scale(1.1) rotate(3deg);}
        40%, 60%, 80% {-webkit-transform: scale(1.1) rotate(-3deg);}
        100% {-webkit-transform: scale(1) rotate(0);}
    }

    @-moz-keyframes tada {
        0% {-moz-transform: scale(1);}  
        10%, 20% {-moz-transform: scale(0.9) rotate(-3deg);}
        30%, 50%, 70%, 90% {-moz-transform: scale(1.1) rotate(3deg);}
        40%, 60%, 80% {-moz-transform: scale(1.1) rotate(-3deg);}
        100% {-moz-transform: scale(1) rotate(0);}
    }

    @-o-keyframes tada {
        0% {-o-transform: scale(1);}    
        10%, 20% {-o-transform: scale(0.9) rotate(-3deg);}
        30%, 50%, 70%, 90% {-o-transform: scale(1.1) rotate(3deg);}
        40%, 60%, 80% {-o-transform: scale(1.1) rotate(-3deg);}
        100% {-o-transform: scale(1) rotate(0);}
    }

    @keyframes tada {
        0% {transform: scale(1);}   
        10%, 20% {transform: scale(0.9) rotate(-3deg);}
        30%, 50%, 70%, 90% {transform: scale(1.1) rotate(3deg);}
        40%, 60%, 80% {transform: scale(1.1) rotate(-3deg);}
        100% {transform: scale(1) rotate(0);}
    }

    .fm-tada {
        -webkit-animation-name: tada;
        -moz-animation-name: tada;
        -o-animation-name: tada;
        animation-name: tada;
    }

</style></head><body><pre style="word-wrap: break-word; white-space: pre-wrap;">/* 
  Web server sketch for IDE v1.0.5 and w5100/w5200
  Originally posted November 2013 by SurferTim
  Last modified 21 DEC 2013      
*/

#include &lt;SPI.h&gt;
#include &lt;Ethernet.h&gt;
#include &lt;SD.h&gt;
#include &lt;utility/w5100.h&gt;
// comment out the next line to eliminate the Serial.print stuff
// saves about 1.6K of program memory
#define ServerDEBUG

// this must be unique
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xEC };

// change to your network settings
IPAddress ip( 192,168,2,2 );
IPAddress gateway( 192,168,2,1 );
IPAddress subnet( 255,255,255,0 );

EthernetServer server(80);

const char legalChars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890/.-_~";
unsigned int requestNumber = 0;

int freeRam() {
  extern int __heap_start,*__brkval;
  int v;
  return (int)&amp;v - (__brkval == 0 ? (int)&amp;__heap_start : (int) __brkval);  
}

void setup()
{
  Serial.begin(115200);

  // disable w5100 SPI while starting SD
  pinMode(10,OUTPUT);
  digitalWrite(10,HIGH);

#ifdef ServerDEBUG
  Serial.print(F("Starting SD.."));
#endif

  if(!SD.begin(4)) {
#ifdef ServerDEBUG
    Serial.println(F("failed"));
#endif
  }
  else {
#ifdef ServerDEBUG
    Serial.println(F("ok"));
#endif
  }

  Ethernet.begin(mac, ip, gateway, gateway, subnet);
  digitalWrite(10,HIGH);

  delay(2000);
  server.begin();

#ifdef ServerDEBUG
  Serial.println(F("Ready"));
#endif
}

int loopCount = 0;

void loop()
{
  checkServer();
  myStuff();
}

void myStuff() {
  if(Serial.available()) {
    if(Serial.read() == 'r') ShowSockStatus();    
  }
}

void checkServer() {

  EthernetClient client = server.available();
  if(client) {
    boolean currentLineIsBlank = true;
    boolean currentLineIsGet = true;
    int tCount = 0;
    char tBuf[64];
    int r,t;
    char *pch;
    char methodBuffer[8];
    char requestBuffer[48];
    char pageBuffer[48];
    char paramBuffer[48];
    char protocolBuffer[9];
    char fileName[32];
    char fileType[4];
    int clientCount = 0;

    requestNumber++;
#ifdef ServerDEBUG
    Serial.print(F("\r\nClient request #"));
    Serial.print(requestNumber);
    Serial.print(F(": "));
#endif

    // this controls the timeout
    int loopCount = 0;

    while (client.connected()) {
      while(client.available()) {
        // if packet, reset loopCount
//        loopCount = 0;
        char c = client.read();

        if(currentLineIsGet &amp;&amp; tCount &lt; 63)
        {
          tBuf[tCount] = c;
          tCount++;
          tBuf[tCount] = 0;
        }

        if (c == '\n' &amp;&amp; currentLineIsBlank) {
#ifdef ServerDEBUG
          Serial.print(tBuf);
#endif
//          Serial.print(F("POST data: "));
          while(client.available()) client.read();

          int scanCount = sscanf(tBuf,"%7s %47s %8s",methodBuffer,requestBuffer,protocolBuffer);

          if(scanCount != 3) {

#ifdef ServerDEBUG
            Serial.println(F("bad request"));
#endif
            sendBadRequest(client);
            return;
          }

          char* pch = strtok(requestBuffer,"?");
          if(pch != NULL) {
            strncpy(fileName,pch,31);
            strncpy(tBuf,pch,31);

            pch = strtok(NULL,"?");
            if(pch != NULL) {
              strcpy(paramBuffer,pch);
            }            
            else paramBuffer[0] = 0;            
          }

          strtoupper(requestBuffer);
          strtoupper(tBuf);

          for(int x = 0; x &lt; strlen(requestBuffer); x++) {
            if(strchr(legalChars,requestBuffer[x]) == NULL) {
              Serial.println(F("bad character"));  
              sendBadRequest(client);
              return;
            }            
          }

#ifdef ServerDEBUG
          Serial.print(F("file = "));
          Serial.println(requestBuffer);
#endif
          pch = strtok(tBuf,".");

          if(pch != NULL) {
            pch = strtok(NULL,".");

            if(pch != NULL) strncpy(fileType,pch,4);
            else fileType[0] = 0;

#ifdef ServerDEBUG
            Serial.print(F("file type = "));
            Serial.println(fileType);
#endif
          }

#ifdef ServerDEBUG
          Serial.print(F("method = "));
          Serial.println(methodBuffer);
#endif
          if(strcmp(methodBuffer,"GET") != 0 &amp;&amp; strcmp(methodBuffer,"HEAD") != 0) {
            sendBadRequest(client);
            return;
          }

#ifdef ServerDEBUG
          Serial.print(F("params = "));
          Serial.println(paramBuffer);

          Serial.print(F("protocol = "));
          Serial.println(protocolBuffer);
#endif          
          // if dynamic page name 
          if(strcmp(requestBuffer,"/MYTEST.PHP") == 0) {
#ifdef ServerDEBUG
            Serial.println(F("dynamic page"));            
#endif
          }
          else {
            if(strcmp(fileName,"/") == 0) {
              strcpy(fileName,"/INDEX.HTM");
              strcpy(fileType,"HTM");

#ifdef ServerDEBUG
              Serial.print(F("Home page "));            
#endif
            }

#ifdef ServerDEBUG
            Serial.println(F("SD file"));            
#endif
            if(strlen(fileName) &gt; 30) {
#ifdef ServerDEBUG
              Serial.println(F("filename too long"));
#endif
              sendBadRequest(client);

              return;
            }
            else if(strlen(fileType) &gt; 3 || strlen(fileType) &lt; 1) {

#ifdef ServerDEBUG
              Serial.println(F("file type invalid size"));
#endif
              sendBadRequest(client);
              return;
            }
            else {
#ifdef ServerDEBUG
              Serial.println(F("filename format ok"));
#endif
              if(SD.exists(fileName)) {
#ifdef ServerDEBUG
                // SRAM check
                Serial.print(F("SRAM = "));
                Serial.println(freeRam());

                Serial.print(F("file found.."));                
#endif


                File myFile = SD.open(fileName);

                if(!myFile) {
#ifdef ServerDEBUG
                  Serial.println(F("open error"));
#endif
                  sendFileNotFound(client);
                  return;
                }
#ifdef ServerDEBUG
                else Serial.print(F("opened.."));
#endif

                strcpy_P(tBuf,PSTR("HTTP/1.0 200 OK\r\nContent-Type: "));
//                client.write(tBuf);
//                client.print(F("HTTP/1.0 200 OK\r\nContent-Type: "));

                // send Content-Type
                if(strcmp(fileType,"HTM") == 0) strcat_P(tBuf,PSTR("text/html"));
                else if(strcmp(fileType,"PHP") == 0) strcat_P(tBuf,PSTR("text/html"));
                else if(strcmp(fileType,"TXT") == 0) strcat_P(tBuf,PSTR("text/plain"));
                else if(strcmp(fileType,"CSS") == 0) strcat_P(tBuf,PSTR("text/css"));
                else if(strcmp(fileType,"GIF") == 0) strcat_P(tBuf,PSTR("image/gif"));
                else if(strcmp(fileType,"JPG") == 0) strcat_P(tBuf,PSTR("image/jpeg"));
                else if(strcmp(fileType,"JS") == 0) strcat_P(tBuf,PSTR("application/javascript"));
                else if(strcmp(fileType,"ICO") == 0) strcat_P(tBuf,PSTR("image/x-icon"));
                else if(strcmp(fileType,"PNG") == 0) strcat_P(tBuf,PSTR("image/png"));
                else if(strcmp(fileType,"PDF") == 0) strcat_P(tBuf,PSTR("application/pdf"));
                else if(strcmp(fileType,"ZIP") == 0) strcat_P(tBuf,PSTR("application/zip"));
                else strcat_P(tBuf,PSTR("text/plain"));

                strcat_P(tBuf,PSTR("\r\nConnection: close\r\n\r\n"));
                client.write(tBuf);

                if(strcmp(methodBuffer,"GET") == 0)  {
#ifdef ServerDEBUG
                  Serial.print(F("send.."));
#endif

                  while(myFile.available()) {
                    tBuf[clientCount] = myFile.read();
                    clientCount++;
                    tBuf[clientCount] = 0;

                    if(clientCount &gt; 63) {
                      client.write((byte*)tBuf,64);
                      clientCount = 0;
                    }

                  }
                  if(clientCount &gt; 0) {
                    client.write((byte*)tBuf,clientCount);
                  }
                }

                myFile.close();              
#ifdef ServerDEBUG
                Serial.println(F("closed"));
#endif
                client.stop();                
#ifdef ServerDEBUG
                Serial.println(F("disconnected"));
#endif
                return;
              }
              else {
#ifdef ServerDEBUG
                Serial.println(F("File not found"));
#endif
                sendFileNotFound(client);
                return;
              }

            }
          }

          pch = strtok(paramBuffer,"&amp;");

          while(pch != NULL)
          {
            if(strncmp(pch,"t=",2) == 0)
            {
              t = atoi(pch+2);
#ifdef ServerDEBUG
              Serial.print("t=");
              Serial.println(t,DEC);             
#endif
            }

            if(strncmp(pch,"r=",2) == 0)
            {
              r = atoi(pch+2);
#ifdef ServerDEBUG
              Serial.print("r=");              
              Serial.println(r,DEC);
#endif
            }


            pch = strtok(NULL,"&amp; ");
          }
#ifdef ServerDEBUG
          Serial.println(F("Sending response"));
#endif
          client.print(F("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n"));

          if(strcmp(methodBuffer,"GET") == 0) {

            strcpy_P(tBuf,PSTR("&lt;html&gt;&lt;head&gt;&lt;script type=\"text/javascript\"&gt;"));
            client.write(tBuf);
            strcpy_P(tBuf,PSTR("function show_alert() {alert(\"This is an alert\");}"));
            client.write(tBuf);
            strcpy_P(tBuf,PSTR("&lt;/script&gt;&lt;/head&gt;"));
            client.write(tBuf);

            strcpy_P(tBuf,PSTR("&lt;body&gt;&lt;H1&gt;TEST&lt;/H1&gt;&lt;form method=GET onSubmit=\"show_alert()\"&gt;"));
            client.write(tBuf);
            strcpy_P(tBuf,PSTR("T: &lt;input type=text name=t&gt;&lt;br&gt;"));
            client.write(tBuf);
            strcpy_P(tBuf,PSTR("R: &lt;input type=text name=r&gt;&lt;br&gt;&lt;input type=submit&gt;&lt;/form&gt;&lt;/body&gt;&lt;/html&gt;"));
            client.write(tBuf);
          }

          client.stop();
        }
        else if (c == '\n') {
          currentLineIsBlank = true;
          currentLineIsGet = false;
        } 
        else if (c != '\r') {
          currentLineIsBlank = false;
        }
      }

      loopCount++;

      // if 1000ms has passed since last packet
      if(loopCount &gt; 1000) {
        // close connection
        client.stop();
#ifdef ServerDEBUG
        Serial.println("\r\nTimeout");
#endif
      }

      // delay 1ms for timeout timing
      delay(1);
    }
#ifdef ServerDEBUG
    Serial.println(F("disconnected"));
#endif
  }
}

void sendFileNotFound(EthernetClient thisClient) {
  char tBuf[64];
  strcpy_P(tBuf,PSTR("HTTP/1.0 404 File Not Found\r\n"));
  thisClient.write(tBuf);
  strcpy_P(tBuf,PSTR("Content-Type: text/html\r\nConnection: close\r\n\r\n"));
  thisClient.write(tBuf);
  strcpy_P(tBuf,PSTR("&lt;html&gt;&lt;body&gt;&lt;H1&gt;FILE NOT FOUND&lt;/H1&gt;&lt;/body&gt;&lt;/html&gt;"));
  thisClient.write(tBuf);
  thisClient.stop();  
#ifdef ServerDEBUG
  Serial.println(F("disconnected"));
#endif
}

void sendBadRequest(EthernetClient thisClient) {
  char tBuf[64];
  strcpy_P(tBuf,PSTR("HTTP/1.0 400 Bad Request\r\n"));
  thisClient.write(tBuf);
  strcpy_P(tBuf,PSTR("Content-Type: text/html\r\nConnection: close\r\n\r\n"));
  thisClient.write(tBuf);
  strcpy_P(tBuf,PSTR("&lt;html&gt;&lt;body&gt;&lt;H1&gt;BAD REQUEST&lt;/H1&gt;&lt;/body&gt;&lt;/html&gt;"));
  thisClient.write(tBuf);
  thisClient.stop();  
#ifdef ServerDEBUG
  Serial.println(F("disconnected"));
#endif
}

void  strtoupper(char* aBuf) {

  for(int x = 0; x&lt;strlen(aBuf);x++) {
    aBuf[x] = toupper(aBuf[x]);
  }
}

byte socketStat[MAX_SOCK_NUM];

void ShowSockStatus()
{
  for (int i = 0; i &lt; MAX_SOCK_NUM; i++) {
    Serial.print(F("Socket#"));
    Serial.print(i);
    uint8_t s = W5100.readSnSR(i);
    socketStat[i] = s;
    Serial.print(F(":0x"));
    Serial.print(s,16);
    Serial.print(F(" "));
    Serial.print(W5100.readSnPORT(i));
    Serial.print(F(" D:"));
    uint8_t dip[4];
    W5100.readSnDIPR(i, dip);
    for (int j=0; j&lt;4; j++) {
      Serial.print(dip[j],10);
      if (j&lt;3) Serial.print(".");
    }
    Serial.print(F("("));
    Serial.print(W5100.readSnDPORT(i));
    Serial.println(F(")"));
  }
}</pre><ul class="fm-notif-center fm-container whencollapsed"></ul><div id="fm_base" class="fm-container" style="border-top-width: 2px; bottom: 0px; display: none;">
    <div id="fm_base_resizer" style="display: none;"></div>
    <div id="fm_header" class="">
        <!--img id="fm_close_main_btn" 
            src="https://plus.im/static/img/close_main_win.png" /-->
        <img id="fm_slide_down_btn" src="./WebServerST_files/down_arrow.png" title="Collapse" style="display: none;">
        <img id="fm_minimize_btn" src="./WebServerST_files/next_arrow.png" title="Minimize" style="display: inline;">
        <img id="fm_slide_up_btn" src="./WebServerST_files/up_arrow.png" title="Expand">
        <span id="fm_back_btn" style="display: none;">&#8592; Back</span>
        <img id="fm_settings_btn" src="./WebServerST_files/settings.png" title="Settings" style="display: none;">
        <div id="fm_header_title">IM+ Bar</div>
    </div>
    <div id="fm_body" class="fm-base-content fm-active" style="height: 300px;">
        <div id="fm_my_profile">
            <img id="fm_my_avatar" src="data:image/png;base64,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">
            <div id="fm_my_st_fe" class="fm-my-st-onl">
                <img src="./WebServerST_files/arrow_for_status.png" border="0" style="float: right; margin: 7px 6px; position: relative;">
                <select id="fm_my_st" class="fm-my-st-onl">
                    <option data-class="fm-my-st-onl" value="ONL" selected="selected">
                        Available</option>
                    <option data-class="fm-my-st-awy" value="AWY">
                        Away</option>
                    <option data-class="fm-my-st-dnd" value="DND">
                        Do Not Disturb</option>
                    <option data-class="fm-my-st-na" value="N/A">
                        Not Available</option>
                    <option data-class="fm-my-st-inv" value="INV">
                        Invisible</option>
                </select>
            </div>

            <input type="text" id="fm_my_psm" placeholder="Set your status">
        </div>
        <ul id="fm_contacts_chats_tabs" class="fm-tabs-holder">
            <li id="fm_cctabs_contacts_tab" data-tabname="contacts" class="fm-active">Contacts</li>
            <li id="fm_cctabs_chats_tab" data-tabname="chats">Chats</li>
            <li id="fm_cctabs_news_tab" data-tabname="news" style="display: none;">News</li>
            <div class="fm-clr"></div>
        </ul>
        <img id="fm_add_contact_btn" title="Add Contact" src="./WebServerST_files/add_user_icon.png">
        <div id="fm_contacts_wrapper">
            <div id="fm_search_field_wrapper">
                <input id="fm_search_field" type="text" placeholder="Search contacts">
                <div id="fm_search_field_close"></div>
            </div>
            
            <div id="fm_search_cl" style="height: 220px;">
            </div>
            <div id="fm_cl" style="height: 220px;">
            <div id="tr=G;id=adriana.chitu@gmail.com;lgn=adrian.fedoreanu@gmail.com" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/ggl.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/awy.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">adriana</div>
    <div class="fm-cle-psm">
        Away
    </div>
</div><div id="tr=G;id=alexandru.grigoras@gmail.com;lgn=adrian.fedoreanu@gmail.com" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/ggl.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/awy.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">alex pachet</div>
    <div class="fm-cle-psm">
        Away
    </div>
</div><div id="tr=Y;id=amalia_plesa;lgn=phedoreanu" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/yah.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/awy.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">amalia.plesa</div>
    <div class="fm-cle-psm">
        Away
    </div>
</div><div id="tr=Y;id=andreea.rarinca;lgn=phedoreanu" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/yah.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABwAAAAcCAYAAAByDd+UAAAABmJLR0QA/wD/AP+gvaeTAAAACXBIWXMAAABIAAAASABGyWs+AAAACXZwQWcAAAAcAAAAHACHsSK0AAAIk0lEQVRIxyWWSW+d52FGzzt80x1J3ktSHCVRYiRZtGXZihM3SREHNVIDqQEXCAJ00xTdddHf4EU2AbrIf+iuQLIKUNiLonBrtw2S1JZsS5FoURJJURwu7/Tdb3yHLLR/gLM4Z/GId18JfO08tYXaggeEgFBBrGCjLXnrasgkc+xNoYwkUSAwlePopMY5yHJHWYEEpIDKejqxYGdZMN/X/P0/3aDR0gg7RYaBIFSCSEGkQQtIAkGsBZ2WxGuoBGxfjrm+pGl6GE4sg7GlrDzjqaOowDpP7TzGQxQIitozs4JEWI72U8JEY41HKwn9OYVwcDSx6BCiWNLsKJb7AY0AXFcTzkVsugp8yfHAcDRySASVBe9ASoEUICXoUICFh8eOnash3bkQIeTLjZJweVHz1lbIelswP6e5uhlzZatJEit0rMlr+OM3OVFTs9KWvHM94WJbMk0t1oFUL4FaC5SEuvJklWdaev5/19BIJN57pPKo25v6wysXAna+1abX0kxKTw2UheNPuxnHxzXPnpc8OawYTy03L8WsrzR47WqDRiB4dlyTFY7aeIyF2gmM8cQCvBQcDwy9puTWGy28qdELvYAokjgPb769SlEd8Nn9GeMahqknFB68Z1p4/mtccDa2XOhXFMbja8sHb8Y0OyGng5rYGT7ZrUhrwZ2eYH9keVwJPv2/c957b4FOL0CrUOKA2Sin25/n7b/UuGqXP97PcFowLT3zTcmPX2/w6YOcewcVj49rmsrz3tvzvP/BTfqLMTpKCITn1sdf8Zvf7PG97Zi1nXV+8W8nHB4XDE5L5voS/eR5RWIUC1pRFzUbN7Z5R8O1a2c8e5py+DyncoJh5ti5GPLOtYA6d1ileH07IdElMrmAiBKsN3znB9tUg3OuvLrF9W/fYuOzj/j0fw+pjEArhc5yx8NDRz8ChMd7WLn2Cms7MbfSMbPTA3YfvOCjjw/4qx8uI5IOdw9K7h+OWD+tuVrHRHObCFNgyjEqCLl+e5nFazexVjOeZuhI0GlLytKhjfGMreBkUHO4n9JdMQyGht5Kl6S3Rthqcb3d5fK1C9RlzWyc8KP3b3Bn/y5XLy/TXr6CUl28FyhdUNYFYRLjnUWKjLPziu++2WFpOaYqHRovmGSOOkn49W8f8++fHOBnBW/d6vOdd3eY33yD7toC+UIKRYnaf0RoBqzeeI2wvYAKOwhehiW8AO+RWhGFNZVLePv1Jj/56wXywhPGCq1dTaIlLyaOn3y/x5OvTsiF4pv9lPW9MzqrBVIEhAJEZ4H+jduoYB4VNBBmjHAVQkV47/G2xjtHs9Pk/pf73L97wA9fFTQjmE1LgriJ/Pk/vEG3JYilJx+lJGtb7Lz/fVbuXObC9jZVNkGpiEAJpKsIdZMgbCFdhvAeRIB3Fm9KbJnhrSVpxJyejvji6zPCZowHbG1xFvTP/vFvufPdLfzoS3a/HtKr4eaio9O/TjK/DNUEAKGbSJPibQ6ufglTDbx3uHKAyceYcoYQEmMlGxdimlnB/d9P+MHfNDC1x3nQZQUrF7dob56ydbnB2XkPV0k6/WWcNVSmxNsCXIWrS1w9wZkKgcc7QEq8K7B1QTWbgJQIV1KnJat9RS+qmY0KlHKY2qODUFGVEZXv4vw53YV5wsYlvJN4UVALTz07QcsAiccLQT16QbCwQZkeYfIZ3tV4b8B7vCmwFYyPR0zGnlduBPSWAqrSoQKJlDpEKoUXCSqQ2HoAzoHJEUIQhi2QGqRktP+Us2+eYF2ICruEnWV0I0ZI8K7G5Bl1VmDSlHsPp6RDx5MXliqztNoBrbkGWkiBwGFFE60UuCmunoAPwVt0nHBy/3MOvnjIXL/Dxvd+RNhsv/Q2PmPy9Jiwl+BMTV0UCCmYTTN2nxZ8PZTIU8vVg4K5XheBeAkEg6WJDJrgz0nHj+h0rmIqg/cVrcVF1t6I6G9eRluDPXpBfXbKdG+P6OIqjW6X6ekUD0hX8/xJii0c3aagriwHz2asrY+YnM/QXijCJKTIYoxPCCNJOhvwh/98weblReJWG+s87VhiHj0iO54ga4OKGyTLc8ilkHL8UoMA8nHB7sMZcSh5dV5yMHZ89kVOJz6n09VopWfs3f+coD1HNNciShS2rPj9x48wP7asbzqiUDP8+pheZonbLeh2qRoCO69BaLy3eGcR3vLs0ZRp5liZV4SRIPeOZlNy9KKm01aoS+Lph7/6l09pMuKVb19D2CGNdsDixhJ/+GrK/vOUb11bJV7sMs0zfCOgjBxqbZlGbxWFoC5SfJUzOBix96cpQSvEe8e08kgP/ZYgt3B8apH/+utvOK0Dvrx7SplBsHYRHUtyA8pbpmnBbz+6x9kwZW5nE3Vlnc6N63T7lwiCBUChlcZWhgf3RoStEKde3o3Tmee8gq01RZk5TA1qaz38MAqhmJa89uoCB89Lpkdj5jsN0txx+84axjr+45M9Zpnj5o0NhNU4W+FdjqQmG5/z+X/vcT6sWb3SZTqusMbz8MSy0JIszklKC8Z4NMbhADEX8ctf/Q95Yfnnv7tE57VlhD/j4NmAxw/OKKzgd3cPaTYkf3FnG2s94/MRx09PeHx3nyyt2drpkxUGhSctPMPSc8F6ytKztqS499igt+cVAykJI8FwZOi0QnQUMxw6oigim47JjGd5MSJNDb/7/DlfPThjo6MIJhPGo5LuhXku3l5AUJE+GzOZOfIaIilwApqxYJo6NKDPBRjnKacOYzy9rmY0zHn2/JCkmZDETZpdRzMJ0EpxcDgjryqM0/z0g3dJWg2MLRgePmFykFLmlkFqCSLJageW2pJh5pmVcJ575Or6PHXtmeWeWeG4uNIkSQJOBlMm4xQZtpicZgzOclaWW3Q6CStLLY6OU45HNd3+EkIEJK05dBTinCcMJdPC02sKxoVnd+A5yzwqkPwZTVWHn31WNTAAAAAldEVYdGRhdGU6Y3JlYXRlADIwMTQtMDMtMThUMTY6MTI6MzQrMDA6MDDzagzMAAAAJXRFWHRkYXRlOm1vZGlmeQAyMDE0LTAzLTE4VDE2OjEyOjM0KzAwOjAwgje0cAAAAABJRU5ErkJggg=="></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/onl.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">andreea.</div>
    <div class="fm-cle-psm">
        Available
    </div>
</div><div id="tr=G;id=2ddbrd0ysm2km2ahx6fiyrvf18@public.talk.google.com;lgn=adrian.fedoreanu@gmail.com" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/ggl.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="./WebServerST_files/no_avatar.png"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/onl.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">Antoine Burret</div>
    <div class="fm-cle-psm">
        Available
    </div>
</div><div id="tr=K;id=beaniest;lgn=phedoreanu" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/sky.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/onl.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">beaniest</div>
    <div class="fm-cle-psm">
        Available
    </div>
</div><div id="tr=G;id=cristian.anca@gmail.com;lgn=adrian.fedoreanu@gmail.com" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/ggl.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/awy.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">canca</div>
    <div class="fm-cle-psm">
        Music is the biggest celebration of life
    </div>
</div><div id="tr=Y;id=alex_canibalu;lgn=phedoreanu" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/yah.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/onl.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">canibalu'</div>
    <div class="fm-cle-psm">
        Available
    </div>
</div><div id="tr=K;id=cipribucur;lgn=phedoreanu" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/sky.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/na.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">Ciprian Bucur</div>
    <div class="fm-cle-psm">
        climb high dig deep ski steep
    </div>
</div><div id="tr=G;id=05sdhzdh3eifv377jgkwaq2dhb@public.talk.google.com;lgn=adrian.fedoreanu@gmail.com" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/ggl.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/awy.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">claudiu coldea</div>
    <div class="fm-cle-psm">
        Away
    </div>
</div><div id="tr=Y;id=d_comsa;lgn=phedoreanu" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/yah.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/onl.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">Comsa Dan</div>
    <div class="fm-cle-psm">
        Available
    </div>
</div><div id="tr=G;id=aristodeea@gmail.com;lgn=adrian.fedoreanu@gmail.com" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/ggl.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABwAAAAcCAAAAABXZoBIAAAAAmJLR0QAAKqNIzIAAAAJcEhZcwAAAEgAAABIAEbJaz4AAALlSURBVCjPBcFLbxtFHADwefx3Z3a3u7Z3XedhRa1Tp3mQlhLRolRFgnJANJeII4eKE1+BT4DEnRNfoKCKCxIS6qnqoUKCgqCBUorchCapY3vttdde72NmZ/j98NPBaT9MRslMYGRyOdczyLy7OwCLiYTeWThN5/lYkBwlgLEYGcHoXnNVvyIa8kRjBIQZyKBZOcsAHw+bkTFLRIVDVfRkKambI0z4RIwmlrd+ddcYgskvQleaPDsnh0oIbZrV5NpniyuqEBKj9F+QNSbYJFea0rxQKOsXwz8GDZRdX6Al/gH10jRJizyXRTw4OVOmsmFSN5b2Wy16Z1oQJ6gw2zXlJIzKJZvg5UR5/WfXfBDYLl2SY66D5S3H+Oo1VPLYeVN1xaPL4MduhRpIaYUo4/9EM2sC2Nvd/bzbOSDCrxumVfEsxhiWYquJapeYsyzujo569P0KQUQrYhACWpR/KnnhtPZeXTZDfhs6ts09hSl20oixoNa57K/s7uTS+qIgtI1l7FJkZN9/PRJFzU+Ld/cWc/A8A0zaABlXLPLfl9+WZ93DYG21mnUiMT4qbQdRY1h/BYHAD6al9tl4rWYpFsiD0/Un363Cp7/8CiJY37gQxued2w/71IcyMwd64fD+I5J9Mur/rNqvz6ZAbzRbvT6u2rnesEuv2oTnH1/5Ea+lLz+62a9f54u91pzMJztP6gq9dRMOsjuPb20fk01sSMr9aEbz+I1SbyXVtkHDqze293viOUc2LT30t0SwOXp8qaHgyKSs2F9N5sffVB3FLMt+cO8F7/aWG6YzDjH1Dz9YOjHs+z95aEzOu/MXOllo+zYvX0JO5xc/FBFuRw//SmW8oVs2X6l5thsfZBambG/vyJAuahS/6XeaZR6EiTb59On8HAG69fbOZBqbvHVl89a2YxK+pG0yHQ5sghToFQ6cpQ72QRcpAVXf/j0pSoSlCMmzCNWZRFIj107GqVKqyk7wXMo86vwPvi9wYuXDyTAAAAAldEVYdGRhdGU6Y3JlYXRlADIwMTQtMDMtMjRUMjE6MTE6MTIrMDE6MDB0vkkiAAAAJXRFWHRkYXRlOm1vZGlmeQAyMDE0LTAzLTI0VDIxOjExOjEyKzAxOjAwBePxngAAABF0RVh0anBlZzpjb2xvcnNwYWNlADIsdVWfAAAAIHRFWHRqcGVnOnNhbXBsaW5nLWZhY3RvcgAyeDIsMXgxLDF4MUn6prQAAAAASUVORK5CYII="></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/awy.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">deea</div>
    <div class="fm-cle-psm">
        Away
    </div>
</div><div id="tr=G;id=0st1187eeq1lw1h0jlg11v8rqh@public.talk.google.com;lgn=adrian.fedoreanu@gmail.com" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/ggl.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABwAAAAcCAIAAAD9b0jDAAAABmJLR0QA/wD/AP+gvaeTAAAACXBIWXMAAABIAAAASABGyWs+AAADa0lEQVRIx61VXU/jRhS9d2bimBqHLUkIFBGIllaVaFelrWhf+lCxQv14KJX6N1etuj8DdftQVbSVkBrQgrN2CAmJsT2ee/swEAXisCD1PFkez5l7zj1zLaEIQgghFAADAKIQQiAiMyMKJcsoBTMhSkRhv7FbmK+f5TSj3b+4WGWmPM8REVEQ0ep7rS92vvr4o0+W6suj0egqiQH45mCUUgKA5VUwA/PznufNHR8fCyEBcGfny73n37c2nvZ7F4eHf6TJSOdpv98HQMsrpTTGXFddqB0AqrVas9kEACJqrrV+3P9pZXXl6WarvvQum4RNZgscyx+XWUCKiMYYRPz80882NloAsLW1tbv7fKGysL6+ulj1TX41ujxPk2Ecx8w03qW1llLagtS0m7Va7btvvv3wg/fbJ68Rpes6z55tuXMOA0VReHk56ATB1VVMlMMNKTMzs1LKcZwkSQpIlxuN7e3tXq+nM7201BAoouiN45T7F+dhpzOK4yzXQdAxRCgEE42F53luVd6Sb9f+bbeDIIii6NeXL3e/3t3f/+FycNFcW2XKk6uRztKoe/6O5ymlxiZOMhDR3e5LKYfD4eFfh27ZTZO04vsnx+1ms/nP33/+/uo3KZ1GfZkRCHjOdYdac1Fy1PQ5AHBwcLC5uWlI//zLi8qCj4hnZ6crS7WVlbXmeitOsiCMHMchLuScyqlV9CYM/UpFSOyEnV6/J4SQUjYay3t7e8qZO+2cIkCWZbMyXhx+Iup2u2maSinJGNd16/X6aRBGYdcpl4EJBADdCumtpBe+ZeZer5ckCTMTcxzHR0dHg+FASfm6fWKIGGYyziS12SIiIhp3ubLgjYaDTtABEAAIs6FmVTqZPkQEAAEy6ATt4yMBxIA8m1TC24CIQggi8lyXchNGYZIlxPdtkffTTY61XOtM571BPycSAu3qI+RPwvd9AGCiJ/P+WRgaNkTsOCVm1lo/olFjZ5VSWmtELJddz/d1fs2iM23fF0sslGxbZN00xpRKJaWUVGo0HE7OzYcCEUul0uQowBsopey4fCvuflQulz3Pu/ZbKXuALd8YYyfDo0mVUmmaji+rNc4W+GjVd/ROuyyltMF6iAOy8C7d+Q8qpYjI87xqtWqMuafvxd2fdaMsAGBszv+A+0t7RPjHdNbNh+M/2VjaD08JsbQAAAAldEVYdGRhdGU6Y3JlYXRlADIwMTQtMDMtMjRUMjA6Mjk6NTcrMDE6MDD1b5cPAAAAJXRFWHRkYXRlOm1vZGlmeQAyMDE0LTAzLTI0VDIwOjI5OjU3KzAxOjAwhDIvswAAABF0RVh0anBlZzpjb2xvcnNwYWNlADIsdVWfAAAAIHRFWHRqcGVnOnNhbXBsaW5nLWZhY3RvcgAyeDIsMXgxLDF4MUn6prQAAAAASUVORK5CYII="></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/awy.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">denisa chinanski</div>
    <div class="fm-cle-psm">
        Away
    </div>
</div><div id="tr=Y;id=equalizer2005;lgn=phedoreanu" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/yah.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/onl.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">didi</div>
    <div class="fm-cle-psm">
        Available
    </div>
</div><div id="tr=K;id=echo123;lgn=phedoreanu" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/sky.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="./WebServerST_files/no_avatar.png"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/onl.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">echo123</div>
    <div class="fm-cle-psm">
        Available
    </div>
</div><div id="tr=G;id=13qjfyr232z6r0vlc6o48qbwkl@public.talk.google.com;lgn=adrian.fedoreanu@gmail.com" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/ggl.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/awy.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">Emanuel Cioc</div>
    <div class="fm-cle-psm">
        Away
    </div>
</div><div id="tr=K;id=f_sfetea;lgn=phedoreanu" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/sky.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/onl.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">f_sfetea</div>
    <div class="fm-cle-psm">
        Available
    </div>
</div><div id="tr=Y;id=phedoreanu;lgn=phedoreanu" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/yah.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/onl.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">fedo</div>
    <div class="fm-cle-psm">
        Available
    </div>
</div><div id="tr=G;id=rcflorin@gmail.com;lgn=adrian.fedoreanu@gmail.com" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/ggl.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/awy.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">floman</div>
    <div class="fm-cle-psm">
        Away
    </div>
</div><div id="tr=Y;id=floryn_coman;lgn=phedoreanu" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/yah.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/awy.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">floryn_coman</div>
    <div class="fm-cle-psm">
        Away
    </div>
</div><div id="tr=Y;id=f_sfetea;lgn=phedoreanu" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/yah.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/onl.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">fomo</div>
    <div class="fm-cle-psm">
        Available
    </div>
</div><div id="tr=G;id=fsfetea@gmail.com;lgn=adrian.fedoreanu@gmail.com" class="fm-cle 
        ">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/ggl.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/onl.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">fomo</div>
    <div class="fm-cle-psm">
        Available
    </div>
</div><div id="tr=K;id=fsfetea;lgn=phedoreanu" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/sky.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="./WebServerST_files/no_avatar.png"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/onl.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">fsfetea</div>
    <div class="fm-cle-psm">
        Available
    </div>
</div><div id="tr=Y;id=sterghite;lgn=phedoreanu" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/yah.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABwAAAAcCAIAAAD9b0jDAAAABGdBTUEAALGPC/xhBQAAAAFzUkdCAK7OHOkAAAAgY0hSTQAAeiYAAICEAAD6AAAAgOgAAHUwAADqYAAAOpgAABdwnLpRPAAAAAZiS0dEAP8A/wD/oL2nkwAABL5JREFUSMdVll+PI0cVxc+5t7rd9u6Q0UISbRYR8oSUB8R7iFBCEBIIJMQDX46XfB6EeEIoikgisbszO9kwjMdjt6e7zuGh2rNQli1Xq6vq/vndc4vPnnwcGWzfzIggkxFkog0CBEm4zQ0ESTIIImwbsAHYMGQXELYhOSATQgSIAAAuY9mKy56RQUREMoIRIInTiTCBolpJAlIwVMmIzJBKlsiCKCSBaGYRhDHPM1hDKB0JkhkgAMM2QBfbZJAk2BxRFYxJNaqCbusARqbsOuvJ959sHm0yY78f9/u7etxHFoI+vVkyiw2QjGgeL26CkoBKwGQQ03ToV8PHn3z09jvvHPaHWrW7vb169d2ry8u73U1bExlkyU3/FBAMSwDg05AtGRUwHNKcXfzhT398/4P3j8djlhwP4zzPgIN9le6PY0sVjFzHu6oyLEm1qlbNc61VtdY625Jmhu/2u9/+/nef/uqTWufSd+v1UEqpVeM4juMR5jRP8zSTREXJ0tlvctf+tviStISI8XD31lvnn/360/Pzx0Hk6++Ox/t+tdo8Gob1imSd59Vq2G3/A5hkIWNBsIUW8ImfFoYkx8P405/9+Ic/em+z6R+fbfpV9+L55XE8klxvhrOzs+3NbjiuSU3TPcCCh7EA2WD/n0Goar0efvD2eWZVZSN+GFb7w9j3/c317bAefH3dkCJRLPlk6AM95IJ+o73rysXLi9vtXdeFKq5evT4cRtnTNB324zRNti3dH0dLJMNwq7HmeUtXnes8z9M0TdM0z1O/6r/4xxd//cvfStcfDsf1Zl26EhF1nm+3u7vdfrqfd7utrciwHZJlwEu9kIwglphKda4nGD7/8+d3u8Mw9JkxDKvMvJ/mw/4wT/PNzfbfr68iAiCDuemenRJvyUtM29anyrfU993X33z1zy+//smHH5au225319c3L59fXl1++/xfL7768u/TuAdpyRbfO/85gzYs2S3WbmgZRptbtiPybr979+mzX3z2y2E1bG9uLy9eXbx8fnXxAnBG2CBpmB88/Y2tRYdO9bSYbT1Mm15kxHg4Hu8PpUuw6ZszS5DLJgDI8ujxua2TOWr2qtZmadt3Oa0K0KPv9Ruc1Vrbw1YvVMO62oJdhuGx0ZIFo8qn6NpStaqqLKGxYRlSVclToBp9smS5ShVwOR73JMgCmLHknyUjIFmSVBeWm+VVzuZXtfVGwgE1d2otx8OtAUYSzOxAkJGZrbWUrgC9zbYEsiSAMISKh5oBSNrVsmotqi0VFWTl3PQ0IhgRWbJ0XekzSpY+WhcgYKF1JoIMRoloCKYEqxYyIoMO8CQjjYG5ala9n6cYQQSTzMzMkpFJxvKhwyRTAqhgojTZt0lEJpknTiCrybZqtVU9ealmMjMiF2+YICOS7eSIiCjjfsv2YmvUWch4UCm1ioAlWRUwSE7ROnRbGJFka30tGlHmaTpp9FKVJCMSZiQZSUTDVFWGADXHmgqTjAgy2q9hRhQw0DylgVBVQJVhkDMiuCTEgZPMAAR0ahNerhdB2I2dEgwwkC2dAGlkLPeD5ZnlVoUnteXStOP/LhmCZLOqlK6TBJiErOXCIC9QvxEEnIQ7loyBJ62kbQajuQT/F3Q4orb9kZl0AAAAJXRFWHRkYXRlOmNyZWF0ZQAyMDE0LTAzLTA3VDE0OjA3OjEwKzAwOjAwC7ciFAAAACV0RVh0ZGF0ZTptb2RpZnkAMjAxNC0wMy0wN1QxNDowNzoxMCswMDowMHrqmqgAAAAASUVORK5CYII="></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/awy.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">ghenadov</div>
    <div class="fm-cle-psm">
        Away
    </div>
</div><div id="tr=K;id=greggnogg;lgn=phedoreanu" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/sky.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABwAAAAcCAIAAAD9b0jDAAAABGdBTUEAALGPC/xhBQAAAAFzUkdCAK7OHOkAAAAgY0hSTQAAeiYAAICEAAD6AAAAgOgAAHUwAADqYAAAOpgAABdwnLpRPAAAAAZiS0dEAP8A/wD/oL2nkwAAAAlwSFlzAAAOwwAADsMBx2+oZAAACGpJREFUSMdNVgs4VGkfP/czN8y4FDOKcZukXGeiUSJERK5lUamkVPTURugrKlqRkQm532KUlZZauW1FShc2W1Jq5bKVD1/lK1si7HvG9jy9M2fOOfP+z+//+98PhHy3YASjoRgCQXwn34N1naLt0XQdI4ROYDiEYTiBMEgYp6EIEEFQHEMxnEYwuHz99dvDah7skv3G4OrDEIRgBPQ9KCWKoCjB2Jh4boP0oorZKpihiGEwjsMoiuNgCwYaIfAkgRIwjMLUFR3V0DUI2H+q/Y3LviNgF0UwCP5uIRgK/lU1MN9VXG+y6SBTTZPAEAKFgSqcIHAUJljKWkus1Hj6MEwRpRgjwDoaqWPiIbkQf/OxkpYeTKn9bslNhyy8gzeX3FATuTCZHJIyF1iOA1LqfK34i7VRl++drGt337kPSGIoAQEmCEJjKmo6+x+7+6fQyx+i2FIMYUSuUw6K+MZnu0l/0RA5q3DUSYLESBIlSCDJX2x0KLdiW37dofpHFY9fqKqoAGGgEYFRBgazDYRh1W1rI+IoUALQxYA2lEAxcKsttI6se7gqoVTPbZsa3xQhQWxgDGfgGAkcAEQDDsTIOvsOpRcpKigAJ4MFCNEwlK2xeGvWL/4p5yhQHKbY4mAPwlR0BKdrbyS0v7aX/mp3rFDHex/D0Jqhqk2jqeAERiMJIG8sXL7M3olgKoF8AI6eCzANw0kNw4CMSt+jyRQohgBfQiQGaJIeIQe6v86W972Pu9Ufe2dQ8mg4UHphidtuNt8SZZGAKgIherp6CkwWyASCBA9h35iSDIEo7GKzTeCeOZ8C02GgEYIZ22JOhcZLbH4I+uG4JObXjrj6+w2fZ4JKGriOm+lqXJYCE0UxPV1dFY4yeAbHKUQUwwgcZ5IsbQfPmPpOPcu1c+ZjlOkQZGgqsnHxAhcgZBBCt/ANCc6uSGh7lD8y4ZpYrGm3kaPJZ5C4nqEJS40HzCMQAvAlcZSO09jKPLPgwyFlTQxVTQRCIQQiQY0AJGtXHw5XwGQo0EiciTMZXIF/+s9Wx4ui2/olPR/8iq7reofSuNoGplYqPD4oAJTAMcCIhhJstpqJ2Du1cv3R9H/zDNQGRlUGFBwd7xAYhrOUCDpGxwmUo7Ex+bxHyuWQ4vrC3tGslx9dcn9b4LVL18qex1+EYgQJQodjhIIiW2Ck5xdy5FqHubMfBUpiEEnQ5mnrcwSmISfOGNmuw+gKNDpdga6Eqmlvz6zIvv1scGr2r0+fnnz4O6Nr1CH5Z+MtkdoiB4aqDofNVWYvmKe7DHhmQ1rZmYY2Jlsd+BHUMqQvsl8bJY26+TKne3SZ1zaYxmYoayjPF5is27qpoLaoe+DD7OzMzAz46fn0JbzhmUvGNVFQjKbYU9vKScfa3ch3v/BwXvGf73fFJlBhR6nEhix8dqqLfZaHSyKaeiNqu1wOn10WGmdzMNknRWayRxJZ31E6OHL9zdjQxMTo5NStt+PnXoxuKmsxj8wXHcoSx+W7pjfl9rytfDmgbS6mQEH7QXDIzGeT0da9Kuaey7cci25+sq28Iai00VV6waegJuFe/8nOoYjbA6cfvqsZGmt/NfL37Ox/Z762jo1ffPGutOt/RU+Hb36cvT066ns0QYFrAEOgmcEoAkNKHK7xGl/nhMzkjsHy3v8X9LzL6BzJ7Hpb2Pcp8/GrvL6R/OHpLbK7554OtX/6OD4zPTv5ZeLrV0C8/8vk06np2se99rv/Y+wTTLLmgTYCshGXZz+E4kreCfkbL912yKhyTr9keTJfnFyyMlXmIr289WJTdEu3yf7kkueDk7Oz018np2amuj9PFveOxv7x3jn3uta67Yaeuxc7gbgjIDep3gRgQT0v8fTzyamxPlZqE19mFSE12X96yb6kxaEndcNS7dJr3Auuq/od2i2rb/84OTYz+WZq8vKrsfN9Y7F3esx/lOjb+pkFRbEFQhB3gpodgC4JgTZtGx6/Ou2yW9Y1x6SKFbHZFofTlx/LEUamAVzh4Rw7abVzxhXTqKzUZ+8efvl8b3wi96/x5EfDB1p7hdFSfcdQ0Y+Jiuo68lJE5/oLxDUSOSaWi87UueffWn2q0upotigue+VPhaYRqbaxmUsPJJkfL7Q9W+OYXbe+qqPwzUTF0OejbQNZ/VOJz4ZXSAoFQVGWkUl0RR4F+m1BK/x2OJ29apVzyz6n2SalRpwoM48vNjtRaHok1yzmrGFkqvlJmeGJUp/qTrdLDzdU/XH66YfjHSMJXePhNR08/4MLPfesDI8nCBVQlfJGLwflCYz9s68GNvZtqHnif/W5W9k9Z1mbfVGL54UOl9I7dgU3bfNbjCXVfnVPvEuaLJKvpA1Mx/4+HHhj4ODdEfuInIXrdgnDj+Ckshz0G1MMQpT4xnZhsR4pJd5Zlf6yptDG/gNtb/e2jQQ09rlUdtmXPrA8V7dG1uKaUi4IORXdM3bmyUfP6o69ba9to3LnO2233BtD46iDaYdSTKkhC+FUl4bmKgxF6QuEq4Ov3Het6XQsaF1b0OJw/vaKwlbr3ObAxmcWO6J5jkER3UN5/dN77wyGNL8MKr3DWx9mFrCPoa4l7/cAFJyowsKpFwUUI2GIBYG6JY0CdnpVtdnm3xJLqpbGFy5KrHAqe+CRV8vQFiguEgdVtyY9n3SruG+YeMG79C7HLWzhaj+tpRbfmIITlftg/GJgOkPgbQE0caphoyKvHRtKGmykl8Q/ydak1/pkVqtb2lPmMDQso1PDHoy4l993zmsKa329Ki6XZSDSMzEn6UxQpgh1QNQh/4KPfFCD8QB2UFzfxt0lqdyv/MHapMr5QgewhcO4Im+J0e7jm1sHbdJqDcJTxGlV61LOs/iLQFcFox+8v8yB/gNbbeGEeup4RwAAACV0RVh0ZGF0ZTpjcmVhdGUAMjAxNC0wMy0xMlQxMDoyNzowMiswMDowMDWo9qEAAAAldEVYdGRhdGU6bW9kaWZ5ADIwMTQtMDMtMTJUMTA6Mjc6MDIrMDA6MDBE9U4dAAAAEXRFWHRqcGVnOmNvbG9yc3BhY2UAMix1VZ8AAAAgdEVYdGpwZWc6c2FtcGxpbmctZmFjdG9yADJ4MiwxeDEsMXgxSfqmtAAAAABJRU5ErkJggg=="></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/onl.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">Gregg Fisher</div>
    <div class="fm-cle-psm">
        Available
    </div>
</div><div id="tr=Y;id=my2emai;lgn=phedoreanu" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/yah.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABwAAAAcCAIAAAD9b0jDAAAABGdBTUEAALGPC/xhBQAAAAFzUkdCAK7OHOkAAAAgY0hSTQAAeiYAAICEAAD6AAAAgOgAAHUwAADqYAAAOpgAABdwnLpRPAAAAAZiS0dEAP8A/wD/oL2nkwAABL5JREFUSMdVll+PI0cVxc+5t7rd9u6Q0UISbRYR8oSUB8R7iFBCEBIIJMQDX46XfB6EeEIoikgisbszO9kwjMdjt6e7zuGh2rNQli1Xq6vq/vndc4vPnnwcGWzfzIggkxFkog0CBEm4zQ0ESTIIImwbsAHYMGQXELYhOSATQgSIAAAuY9mKy56RQUREMoIRIInTiTCBolpJAlIwVMmIzJBKlsiCKCSBaGYRhDHPM1hDKB0JkhkgAMM2QBfbZJAk2BxRFYxJNaqCbusARqbsOuvJ959sHm0yY78f9/u7etxHFoI+vVkyiw2QjGgeL26CkoBKwGQQ03ToV8PHn3z09jvvHPaHWrW7vb169d2ry8u73U1bExlkyU3/FBAMSwDg05AtGRUwHNKcXfzhT398/4P3j8djlhwP4zzPgIN9le6PY0sVjFzHu6oyLEm1qlbNc61VtdY625Jmhu/2u9/+/nef/uqTWufSd+v1UEqpVeM4juMR5jRP8zSTREXJ0tlvctf+tviStISI8XD31lvnn/360/Pzx0Hk6++Ox/t+tdo8Gob1imSd59Vq2G3/A5hkIWNBsIUW8ImfFoYkx8P405/9+Ic/em+z6R+fbfpV9+L55XE8klxvhrOzs+3NbjiuSU3TPcCCh7EA2WD/n0Goar0efvD2eWZVZSN+GFb7w9j3/c317bAefH3dkCJRLPlk6AM95IJ+o73rysXLi9vtXdeFKq5evT4cRtnTNB324zRNti3dH0dLJMNwq7HmeUtXnes8z9M0TdM0z1O/6r/4xxd//cvfStcfDsf1Zl26EhF1nm+3u7vdfrqfd7utrciwHZJlwEu9kIwglphKda4nGD7/8+d3u8Mw9JkxDKvMvJ/mw/4wT/PNzfbfr68iAiCDuemenRJvyUtM29anyrfU993X33z1zy+//smHH5au225319c3L59fXl1++/xfL7768u/TuAdpyRbfO/85gzYs2S3WbmgZRptbtiPybr979+mzX3z2y2E1bG9uLy9eXbx8fnXxAnBG2CBpmB88/Y2tRYdO9bSYbT1Mm15kxHg4Hu8PpUuw6ZszS5DLJgDI8ujxua2TOWr2qtZmadt3Oa0K0KPv9Ruc1Vrbw1YvVMO62oJdhuGx0ZIFo8qn6NpStaqqLKGxYRlSVclToBp9smS5ShVwOR73JMgCmLHknyUjIFmSVBeWm+VVzuZXtfVGwgE1d2otx8OtAUYSzOxAkJGZrbWUrgC9zbYEsiSAMISKh5oBSNrVsmotqi0VFWTl3PQ0IhgRWbJ0XekzSpY+WhcgYKF1JoIMRoloCKYEqxYyIoMO8CQjjYG5ala9n6cYQQSTzMzMkpFJxvKhwyRTAqhgojTZt0lEJpknTiCrybZqtVU9ealmMjMiF2+YICOS7eSIiCjjfsv2YmvUWch4UCm1ioAlWRUwSE7ROnRbGJFka30tGlHmaTpp9FKVJCMSZiQZSUTDVFWGADXHmgqTjAgy2q9hRhQw0DylgVBVQJVhkDMiuCTEgZPMAAR0ahNerhdB2I2dEgwwkC2dAGlkLPeD5ZnlVoUnteXStOP/LhmCZLOqlK6TBJiErOXCIC9QvxEEnIQ7loyBJ62kbQajuQT/F3Q4orb9kZl0AAAAJXRFWHRkYXRlOmNyZWF0ZQAyMDE0LTAzLTA3VDE0OjA2OjA1KzAwOjAweudmEwAAACV0RVh0ZGF0ZTptb2RpZnkAMjAxNC0wMy0wN1QxNDowNjowNSswMDowMAu63q8AAAAASUVORK5CYII="></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/onl.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">Horea</div>
    <div class="fm-cle-psm">
        Available
    </div>
</div><div id="tr=G;id=09u36x4r0x0db2jle7q3eu7bju@public.talk.google.com;lgn=adrian.fedoreanu@gmail.com" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/ggl.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/awy.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">Iancu Stoica</div>
    <div class="fm-cle-psm">
        Away
    </div>
</div><div id="tr=G;id=2pgbnhtjnwq7w1ga64ogbz5ze8@public.talk.google.com;lgn=adrian.fedoreanu@gmail.com" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/ggl.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/awy.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">Ioan Crisan</div>
    <div class="fm-cle-psm">
        Away
    </div>
</div><div id="tr=G;id=javier.ortiz.78@gmail.com;lgn=adrian.fedoreanu@gmail.com" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/ggl.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABwAAAAcCAIAAAD9b0jDAAAABmJLR0QA/wD/AP+gvaeTAAAACXBIWXMAAABIAAAASABGyWs+AAAG30lEQVRIx01VW28b5xGd2/ftLrm7JEXqQpG62JZtKS7QJkDRpgiaugX6CwoU/hX9R33sU5+atyIt2iDXOoVr2K4TN47k2LJkiaRIarnLvX3TB6VAB4PBeZmDcw4wGLx377fMjAiIRIyICgD8fSkzEDMTC7NPnFVFmi+3+5vgFImJEACIiIicU2YhYgQSAFBVIiZiZiSC/5GKYSeMVzvMjMi+56siAAEoAP5fE6IikCoioigoEgEhMiISM6oqESERAiKQZ31jDCIC6HK5zNNcV773pQCIqICARERIjECIJIgICIjIzAiASMyEiEzoN6Kqqk9H0zwvPM8bDtYC62eUERlFJWIERELEKzVCyFdYlBiIgBiQEAERmAUAPS949PjZZ59+tlgsEJxveG115f27d7c3V7UqOQgRFBGQvhd5Na8siIpRYkV2IMJI5ACp2Yy/+Mc///bXP690Otd3BqFgN/JB8OOP/v7O2z98992fJEVFxl7liUKEwkRIfMUuoARAV1kAMhB6fvDgwb/uf/H5/u29djv2rBdaaTW8rX7n7o8bf/jgo9Xh7lv715JFKSyISMRCzETEwiSIJFfekZnFAJINmi9evvjww7/s3745HG5FUcd6fiAkoA5gsNG695u7v//jn67t/K7ZDPJlySxEwoxMzGyuoiMmIWIWi8TAhkzw5MlXURx3u50gDP049qPYxi0TRhBEJwn9aP/g5+8cfPrZx0HDiAEWZEZiYiFiAHSASiX7FYkjAABhWWTFixcvo7hpvEblWD3fxHEQtsPVNYxW3kzxyyffvPeL96aT6eViSUyINWpJLoc6gyqFOoUqEeZmmV9CniogBGWuyqRxHE3ni9enVSdv3joY7g52Sdzx6cm3k9NhcLmzC6Fv5+NxFFoGJRKHAIzIQkxMLPnkTboYa5WEnjSjICuV6qLMy6LOrt+6aXvtWX4xSbxWkyJJfIGo108qxLpaCbDTClCdNR6LiBG5OkQxfOvmduDVrYhbkRdHgbB99vVRRbJ7+8CFa5cSljUkr19FUGJvmKzvzN6MVoX62/3+WjeKQz/wrO97vi/WE2PFGDaGjbWjs7OT45OT47NG0NhYHzw/fBN02uR78f7b+3d/zcJ+uWzo8tbe8Ke/+uXk6BDODg/29/y4TYKOCEiADJIgGSQhspwUPBufzaazZJa0fRwO+6VrOnQe26gqG9OTxuLCVFmv29tfj07//Ui12Yr49s4uBoErCxELYpEsERMRoRCKrPS2iimA5j5Bux0DwXCwVryqW63OYH1rMNidzMcTRX+wMyspr7KwvWqgUdi2cwuQJrAgGmBAUkQgVKJKEK1zrE6RwBrLwkaqallQh3s7fRP5cJFn4/HT+w++Xs4Dyzbudbob3SjorjQcNRXZiCEWUER0ZZmIqNRYAzsENcKBCZLx9OJ8zig1QZLNHz96+N1/vlnd2NnY3mqtrndM9fDRg/OL9PatgdjIOdy9ttuKGkAEwMt5+t3hU4VCXDVDqrFWFhRrqyzLk2kJ7YWWaZK+ORmZRrM73N7ZvxMy1ufPd65v1rKuKFWpm9evXdtaQ1WHCkC1L2enHkEtVKR1BazMiOjzsizTWdqOonSJJdi9g5t5Os/HrydfmQvV2+uN5mD16dE4X1zK+mqj1UIAB8oKCjVZbsdrZTYhB6BagxYGnHVQZhT44WbL9+t89ObsYjJ9+fJkY2tHmr40zWhRPH38IpmOrWcAXVWVCuAAAQkQECCMQlWWIp85lwo6tL411seLQ7c4nLXn47N4krVXe8++OUIONvsDAT0tynqRNtut5y9m/f5WkS5RPQECZUAFAGEDaqTIalDImeeZPB9Vx0n76LI3Oio9pun8HI0Jw87Ry+NZktZpZT092O5O0uqTDx5uXr/jrxKicepAVa/eFSCC8PbWzeHO3rwIarN9eB4cF7u5XofLie2s51VVpEetuNcI4yDubmxs+FK2w/Dwu1cn58Th9vGk7u+udJpGEAERAS8vF7N5zq3h3lJ7Sb2xwHbmvMo1iUOoLmvTFLlhJPN9IuYg8hWl1fAI7LNvj0AGK9fu3H96+uWTdHzBQQB+w4jgbLI8PzuTk2ngXOHQJ6+B6EFtwfkqPVRwuK1edeOOF3mNZZ0YG0aWzk9Hte0mSz0+OU0y//HXF8evZp983n3rRtiS5Ae7/dB3HPTeLx2yeFAHIp1KPYRI2QpLRV5vvdvrwM0beyut9WbQqB3OLuukpMmoSi983/aLoiiWyTwtT0fj89Hy9euR8Q1j72dkV0g6leMaDHGTMUIvqPNUDAk3tDzZ6FtiJAfLZZ4VOJklWebllTbiOE2EpciLrMyNq7yyLhZF/V9uDf7Av7bMWAAAACV0RVh0ZGF0ZTpjcmVhdGUAMjAxNC0wMy0yNFQyMTozODowMiswMTowMBxt27cAAAAldEVYdGRhdGU6bW9kaWZ5ADIwMTQtMDMtMjRUMjE6Mzg6MDIrMDE6MDBtMGMLAAAAEXRFWHRqcGVnOmNvbG9yc3BhY2UAMix1VZ8AAAAgdEVYdGpwZWc6c2FtcGxpbmctZmFjdG9yADJ4MiwxeDEsMXgxSfqmtAAAAABJRU5ErkJggg=="></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/awy.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">javier</div>
    <div class="fm-cle-psm">
        Away
    </div>
</div><div id="tr=G;id=1px3lxqvh4lfz12xl6dqndw44u@public.talk.google.com;lgn=adrian.fedoreanu@gmail.com" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/ggl.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/awy.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">Kirsten Cowart</div>
    <div class="fm-cle-psm">
        Away
    </div>
</div><div id="tr=G;id=lexiflexi@gmail.com;lgn=adrian.fedoreanu@gmail.com" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/ggl.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/awy.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">lexi</div>
    <div class="fm-cle-psm">
        Away
    </div>
</div><div id="tr=Y;id=lucir_bv;lgn=phedoreanu" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/yah.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/awy.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">luci</div>
    <div class="fm-cle-psm">
        Away
    </div>
</div><div id="tr=G;id=0acvabr7ps2c12g3a8xauqonrx@public.talk.google.com;lgn=adrian.fedoreanu@gmail.com" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/ggl.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABwAAAAcCAIAAAD9b0jDAAAABmJLR0QA/wD/AP+gvaeTAAAACXBIWXMAAABIAAAASABGyWs+AAAH1klEQVRIxwXBW2zdZQEA8O/6v55Lz62n7U5L144e1rKt3ebYhRklAYlBlMSoMZk++MCDJPKiaIyJia8mPpCICQH1YS/G6HjgRYQEUNwYbBaErexCW85pz63n+r9898/fD9bWTtZX1xC223f3D01XX/zdz2ZK2MEily+8+PI7m9tjgdnHmx8cNHcYOwAWSKGVUIR6bhBUKgUEYb83iNUIAJT354KwEOayaDIYiSThMWNRdPH8RqngBb6DIAWaaCOPrj3Q3NsZjnqOC4NcBlFMCILWGC04T3vdLsGuUTgdAh9nxsN2NOwT7ZFSqagkkwxWClOPnl2dKfs8iTBxpLQpiyei63o0CDwZMSOgH2aZiWFgOVc85UbqQrbIc1Yph8VjDFUy7tuqJoVKGVKQ98shhQ8+OAsER8ZaaA3QlLqTQToZpwQHKR9j4xilKfUthBRakFiodeiH5SKYX1y6dfujXneCERunLeSFmdE4MgjWFmvVSigkt9ixiCijuRL5Qs6hTi4sBG4+G045JIgirg3N56uFXAUCMhwNMznnzp2P/YyDKPGyQbvbIKVSqVwqtbvDpaX5wCejib11fz/r+9EwZsrGPHIQGQwTzRAOKQTSxaFINfYcaSOlleMiA3m7ddcLPTegEBCfBoRxViqUqlX30FwRAGev2+8M04TZVqvXaO5zBZbnq7P5zO7d7W67Vc6WLEcp5FInyGFOYD7d2sQYUscqxZQC0IhCboq4gSuV4YIvLJSAVVLFyqpDCwv3d9pnzhxfWVlgbNTrdJITM1ufNK5fv720dLjRacSsG0cHTCTakmp1mjMqFVhcWFEpWagt4YtffzKNZDaXferJjSIlxmIF/Ovvbf751b9fu7q5t7tdLuQK2awSqnao0h9NdlstRVLqScljjBHGGCIUjdJyaf6JJ56JRvzmzU186tGLjKmV5dnHLxwnioeZ4nvvb//ihd/ufrbdbTRvfXBj8/3/ZqZmCuUyhJJicuv2J4mJmUp1KgFA0GCeSASI72W3tu5FI7a4cBiN+mMlZTZ0KHGgH7Qn6eW/XOmPomI+PFdf+tbZMzUnuPLq5btXb8BEZQO3VM5AqylyEHCBIsjQuUptrf4whYhFQ0zkF817pN8baQmsRSlA1z7+rDuBiZZKRPliRRs2jBNAgEedK5f/2r63vrSxHjjhqD0pFIuO4xvJtNSCG2IpkCZN47kHaqcfXce56dlidoqzyCtkthptCV1gwNbNG4SzR9bqp1eXd+/cOVydvbC6cubYSjHwevs9AHwurdTcdTwtdJpwq61SKk7i0WQYxxO8cuy45hJTCIKAA5zGk+b27sl63VPqsS+tnarPXjy//uWzx752fu3k+uEMlKtHlnc6B3vjkQVGSwkhEpwTSg2EUkolVTSOSEBdIZPuZNDodjyKytlCu3kwN3/omR89ZaIhQOjEhQ1SzehOp3t3/6Ad1U49ZEMfoDD0/SEfaM38wBVGKmOd0EPKAAgQBMBzHQTgXqMZUL+z1/FdL/Td+WrFQcRxvC8+3xEJp04mkWYvlm9/+sVHt+9gYBDwMHBcGnCmrVQUAM2l7zjVyjQZDQc+JooiyyxSsLHTMIq0Wu29TqXfGcGcrtYeGDca3Vje+HT/zf/8714KNcz6lAhpPBpYIzlioeMoLbHnlaenIUb48JH6QaujAMzmC+loQgycKs7cv/e5TtjR1SNO0Vtb33jzrZsvX37j2o2tYrVincIgjTFCVhsIrEMQsJaxeGauaiBwAk9aS3iSlgrFRGtoAKXUcSlxkCHk9X9/+Hm7rzR79cq/7n62vd3onjtRrx+pNj/YCXNuGGQm3YFgUTYbYOBhovysb10c8RhiQuLRAPqZubn5OEpS36UZj7poujbT3Nv/2z/eCBwqhCx4zomVpae/chwj2uoMJkHgulNOmOGDUedgOB72IjZBvkMpGR/0tNYkW63xRHQncrfdK02MH7pK7VNr+91BbW5BpREgk9XF2ScvHDtxJH/3gNxvDYyvBQfQc7WbN1rQslclWAMs4tQoFPouaSeUpcZEKcBT93cPHKyTNNYsUVF8fuP48lwe88HRxcrDKwtLa2uvvPh6rEwAyDhiyCAIUCZT1JqRwJXaIk8ViiXPM5iE8zxhLIllOqHAaKEoIRAggr1mc2dmpnD2kfX5hRlvKvun166/8tr7XsYHFkqosIFaKJYkSTRJGRccUBIkQsaCw/zcBeBKI7mKuBs4FvoIu8L0EchiSIxICiHJZEiURL2xzZdnjZHWOExJBwNrrBDCGOX6HvWzSpjDNf+XL3yfVKfRdit2oDWWSetaYF0MMcwhhC3QWtK9XqJ7nHphJpOjxBPK1UgAJYXQRiutpNEKIiukWajl/vjSC2tLBfKbX1967vnfD/t9YBKtPOjAOE4kE9WZwqVLj4toOJXLAyiSBDXbk3++9WHMkD+V1UC7GHEhFZsgoBXQFshf/fwnDy7TbrOFf/r8JaXQ1bffxRhTmtHSPP7Y0e9999jzzz2N1ODc6fojp5a++Y1zWgx/8MPTF87XtZT7zUkSKWCEVVwkQ6ASnkQbG/UfP/vMZLSHoIu/evYkoODtd64ZTZTR3/n2uZf+8KwHk1MPLfVGySgWQiRcj/db/dmce2g2d+bcQ/Wj81ffuzYYCoqUFrFVqVHx4uL0keXZNDEaw/8DM02V2TiARiYAAAAldEVYdGRhdGU6Y3JlYXRlADIwMTQtMDMtMjRUMjE6MDk6MDkrMDE6MDBoSoJyAAAAJXRFWHRkYXRlOm1vZGlmeQAyMDE0LTAzLTI0VDIxOjA5OjA5KzAxOjAwGRc6zgAAABF0RVh0anBlZzpjb2xvcnNwYWNlADIsdVWfAAAAIHRFWHRqcGVnOnNhbXBsaW5nLWZhY3RvcgAyeDIsMXgxLDF4MUn6prQAAAAASUVORK5CYII="></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/awy.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">Lucian Attila Filimon</div>
    <div class="fm-cle-psm">
        Away
    </div>
</div><div id="tr=G;id=1eprolnb3jzbi0zk35bzjfs9yd@public.talk.google.com;lgn=adrian.fedoreanu@gmail.com" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/ggl.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/awy.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">Lucian Popa</div>
    <div class="fm-cle-psm">
        Away
    </div>
</div><div id="tr=Y;id=lutea_ionut_ovidiu;lgn=phedoreanu" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/yah.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="./WebServerST_files/no_avatar.png"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/awy.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">Lutea Ionut-Ovidiu</div>
    <div class="fm-cle-psm">
        Away
    </div>
</div><div id="tr=Y;id=madac_1999;lgn=phedoreanu" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/yah.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/onl.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">mada</div>
    <div class="fm-cle-psm">
        Available
    </div>
</div><div id="tr=G;id=2e4fochox67c63i58rjwuwveyq@public.talk.google.com;lgn=adrian.fedoreanu@gmail.com" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/ggl.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/awy.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">Marius Stoica</div>
    <div class="fm-cle-psm">
        Away
    </div>
</div><div id="tr=G;id=matei.dragu@gmail.com;lgn=adrian.fedoreanu@gmail.com" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/ggl.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/awy.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">matei</div>
    <div class="fm-cle-psm">
        Away
    </div>
</div><div id="tr=K;id=matei.dragu;lgn=phedoreanu" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/sky.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="./WebServerST_files/no_avatar.png"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/onl.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">matei.dragu</div>
    <div class="fm-cle-psm">
        Available
    </div>
</div><div id="tr=Y;id=mihar_bv;lgn=phedoreanu" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/yah.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/awy.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">miha</div>
    <div class="fm-cle-psm">
        Away
    </div>
</div><div id="tr=G;id=pbastogne@gmail.com;lgn=adrian.fedoreanu@gmail.com" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/ggl.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/awy.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">philippe</div>
    <div class="fm-cle-psm">
        Away
    </div>
</div><div id="tr=G;id=2o7b2h6bqr1fo2wi157h5uwn4t@public.talk.google.com;lgn=adrian.fedoreanu@gmail.com" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/ggl.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/awy.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">Radhakrishnan Mudliar</div>
    <div class="fm-cle-psm">
        Away
    </div>
</div><div id="tr=K;id=raflobv;lgn=phedoreanu" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/sky.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/onl.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">raflobv</div>
    <div class="fm-cle-psm">
        Available
    </div>
</div><div id="tr=G;id=1zj7sg2iu5gbs0r5m6adjzbvm6@public.talk.google.com;lgn=adrian.fedoreanu@gmail.com" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/ggl.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/awy.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">Razvan M</div>
    <div class="fm-cle-psm">
        Away
    </div>
</div><div id="tr=Y;id=rupulusuus;lgn=phedoreanu" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/yah.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/onl.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">ruben</div>
    <div class="fm-cle-psm">
        Available
    </div>
</div><div id="tr=K;id=rusu_mihai_andrei;lgn=phedoreanu" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/sky.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/onl.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">rusu_mihai_andrei</div>
    <div class="fm-cle-psm">
        Available
    </div>
</div><div id="tr=K;id=ryandouglashanley;lgn=phedoreanu" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/sky.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="./WebServerST_files/no_avatar.png"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/onl.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">Ryan Hanley</div>
    <div class="fm-cle-psm">
        and we're off!
    </div>
</div><div id="tr=G;id=3py0rxc9e5sb91biqv1w53zvbv@public.talk.google.com;lgn=adrian.fedoreanu@gmail.com" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/ggl.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/awy.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">Ryan Hanley</div>
    <div class="fm-cle-psm">
        Away
    </div>
</div><div id="tr=Y;id=neptune_tower;lgn=phedoreanu" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/yah.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABwAAAAcCAYAAAByDd+UAAAABGdBTUEAALGPC/xhBQAAAAFzUkdCAK7OHOkAAAAgY0hSTQAAeiYAAICEAAD6AAAAgOgAAHUwAADqYAAAOpgAABdwnLpRPAAAAAZiS0dEAP8A/wD/oL2nkwAACLhJREFUSMc1lslvXOeVxX/f9+aaB7JIkUWRsjWRsp3QkgfYRroDo+P+J7qzDLqz8aZ72XAWARIgayN/QwInWQRJd4zs0rDdlmV50khSFilVUcWaX03vvW/oRTnLu7g4OPcc3HPE2z943QZBgNEGrTXzZE4URvieh9IaIQTWWpRSGGMwWLAWAJUprLV4noe1FmMMQghc3yNLUsbjMVJKsixDSonv+7hSSlzXJSyEJGmCsZZMZeQLOdTMIKUgCAO0siiV/R0Lay02WA5CCIzRSOngSImQkok25KIIC5QrZaIwwhiD67iCKArRWpPLRURhyHgyAixBEACWKMqhlCaeZPi+j+c6S0AsAoG1AikBAWABi5B5PM/HcaBcKWGtRCuFKxxBEIWkSUoQBsSTMVEuJF0osAJYniyMQlzfRQLWgNIax5VLhgjEd0yFWAKHgSEXaTzfQ0owxuLkAlwpXKw11Oo1oigkSefoTBH4Ll7g8ejohFq9RqEQEQQuWuml3mZ5WkeCdCUIgfxOXiss1lgiIYGltlIAwsENw5BisUgQejiOpNFoMBnHpFlGGIWcHD9hZ2ebIFzBcT2MVmhtMMaSpgme7yOlwBqLEIL5fE4YBniuB0KijQZrsdYiBLjVSon19XWSJOHk5DFrjXV2LqxirGEST/E8l5WVFbCCKMqhTYZKNUIK4njC2VmX+kqNarWKtVCuVAjDAJVptNZovXQ3CLIsxfV8n0wlfHbzFp/f+oKVlTrlcpm19Qa+51EsFomikGF/xJXdqzzrtClXiixmKZ98dJPRcEChWKJaq7KyUufylUuUCmXq1QKu55KkCUmyIFmkJEmC+NUvf2aPj0/40x//hO97gMBgMVohkARRgM40nufRbG6wtr7G9vYON29+ytdf3UEISZIs8P2ALMtwHEkURaytNdg632SzuUG1UqNcqvCkdYL4xc//y/7+g98xHI1wHIcwCvE8Z+k9KwhCnzRTJPMFcRwDAq0NjcYqjcYq9+7fx5HOd5qmOI6D1oY0TchUShiEGGN4550f8c4//winVAzf+/bRMbtXL7O/v0++kMP3fQI/wPddmptbSCkQEvzAR+uEIAi49sIu1VqNwaBPkiaUSxWSJEEpBViKxSJSuqRphhCCg4MD9r+/j3j9xktWKcWNG9e58fLLrK6fI18ocPjgPl4YMF8klPIFDo4ecvebe5w8OUYpxf7+PtVqleOTY27fusX58xdI04R4HHN21kUISalUotvtUq1WkRKm0znOO//0w/eCIODy5Su0TlscHR7iSsnt27fRmeL6/j5Ka86dO0djbY2Nc+doNpv0+wOklEjhEMcxxlguPLdDlMvhui4qy7DW4jgOYMnnI46Pn+BGuRy3bn1GHMdMZ3OKhTyHB4cYYblz5w6z2RRjLIjlcqVcJUsVQoA1hrW1BsXiq9z+4gs81+fypUus1Ov0el1arRZYwelpB2Pg/PYW7mg4whiD53kMuk8YD4d4vscimeEIj//5y4eUK0Xy+TzWCvL5PIHvA1AqldHG8A//+Dabm1vcvXuP5y5e5MVcjvbTFu12i4cHB0ghGY1jqtUyTqNeea9SrnDx4nOcHJ9wfmeb733/BS5cuIgxCpVpnn9+h3gcs7raYDqdUigWePL0hEePvuXNN97g6dMTPNejUMjhuB6Vag3HdamUazS3ztPcbuL7HsV8AXd37yqFYpHZbMorr71KEHrUqjXK5Sqj4YDxeEKSKOazFMeF+WKKMVU8z2MaT4njmNPTNvl8kevXr5MmKb2zZwyGQ5TKaLWe4EiP7e1ttNa4u7tXieMZWhvObTRZzGZsbmwgpYvnuVSqJWr1Old3d+n3ely+VKJQKCCEZbXe4PDwiF6vx2w25caNV2i124zjMSrNyBcLeF6IRFCv1fE8Fxn4EWmSkGYJ//fJJ2hjOD55QpLMCKM8nucRx2OCIMACSil6vR79/pDhaMRZp8NsOiXNMjrdDtf29ijk8kxmM/Z297iwvU2r3WY4HAAgn3XPyBUijNIcHR6RZRnFUpHBaMyg12drcwsQfPrpp/i+S7fbRSm1NMJwRKfTWYL3hzw6esRHn3zMYrEgl4t4+OAh8/mCZJHw5ZdfIh2JtFoDMB7H/Phf/4Wd7W0GgwH9fp+jo0fEkwme53J6ekq3O2BlZYWXXnwRx1l2FW0MjuMgBBw8eIjjOCijqVarrG00QEKqUp62nqKUxt3bu8bde3e4e+8O8SRmPlswHo/wA59MZXz91dfMFwsKhQJZmrB39QqdszMmkymeu3xd0rP4gc/Z2Rmf3fyMSqXMdDqjWCwCyyys1Wq0T09xP//8Ft1elyCIePztYy5fuszWVpOPP/6YxSKhsbqKlA7b57d48823+N7LL3P/7l3KxRLjSYzKMqbTKVEux/bODo6z7Dvdsw5KKTbObdA6PWU2nZDP5XGl6/Hq62+QpSlXdne5tvcCzzqn3L9/n3arQ61e5yf//m+UyhVmkwl+EFAoFcmyBZValcVijh+GuI7LYj4jVYosyyiVK2xsbvCsfcpsOiVLM9rtp7ivvv4aT09aDIcjjh8/5r///GdyuRDXdfADh36vx6/ff5/nn7vIu//5HxweHvK/f/sbnWcd+r0eo9GINF1gDWRZSpqklMplgsDn2rVrnN/ZwRpLPJlw/Phb3Hd/+lOmkxmO46K0Zn19jWdZQqfTxXFcRsMxx8cn5KMcBw/u8YcPfs8Hv/ktmTIolQLgez5hFBBFEUEYMhoNmUxmaGW4/sor5MMIpRXT6Ry3NxhRLBRI0xQktNttgiDihRdfotncJMpFrK42KBbz/PXDD0kWc65cvUKxVCaXz6PUMu8G/SGn7RZaK7S2ZFlGkmbc+fobVJYRT6aoTOGurq4yGo3QWpOmKVJKqrU6YRhy1j3DKMXBgweMxmNGo3hZlOMxzeYm2hikECitmM1mgMD3AyrVKm/94C18P0ADvUGffm/IZDLl/wFWzG92wfz97AAAACV0RVh0ZGF0ZTpjcmVhdGUAMjAxNC0wMy0wN1QxNDowNzozMCswMDowMEmSJWkAAAAldEVYdGRhdGU6bW9kaWZ5ADIwMTQtMDMtMDdUMTQ6MDc6MzArMDA6MDA4z53VAAAAAElFTkSuQmCC"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/onl.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">smirnov</div>
    <div class="fm-cle-psm">
        Available
    </div>
</div><div id="tr=G;id=1p3irjyjw2mj93v8hg2ouhnvss@public.talk.google.com;lgn=adrian.fedoreanu@gmail.com" class="fm-cle 
        ">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/ggl.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABwAAAAcCAIAAAD9b0jDAAAABmJLR0QA/wD/AP+gvaeTAAAACXBIWXMAAABIAAAASABGyWs+AAAD3klEQVRIx5WWT28cRRDF36vumfHsf9trKzEkseMQGVAScbNyIUKAEJJl7iCkHJHyFThy4MZn4YhQOIRDOMCBgLBiGRBxiEwgimPv7uxMdxeHGW/WG9tJSnuo6t1+Vd07+3vLerulqiQBjCcAyvzZsszLxfEY7bU4Pia2nVyOhz2u7XjzZ1VG+fghRov2paY7ueuoPFp04jaP3H94UVXLnADsxCxHdn5+ECRQKVHw4sHnDDt62SOfElUAekiCIBVQ8umTx4PxhFAFqFACsKMvToOCowbAqDgYRaQaVRWEggRJLT+oQAgBoAIwUWrLPQooVSUAhhAKCE8YwgiFRiNoopYSYkFhIgKJWh8NrPEREqGAhag1qhZKLVUJUSEsFIADctCQAhZkoJFAa0yWplOSBzgfqfcytDbpxGnTukGR9x0yFw9zmCipQaU8lkAjqIiCELGggCKMDYTKiDY1dq6WrZx1JpNekII29vlbS713rvrLF1ud1D/Z7Q9dbJIkIZRUInhKppKHIi984elc5L1zfhfIG1NxGhf7vd31D9///IvPNn79cevBQIO9erl5/ePF9U9uvP3BjWvvrm5sbf50554VI1BvJEQR6rF26256mvNd22qYB/f3GrV0cWl2ebmxtNT9+pvHN29urq29ubj4eqdZnJmt/73zz/pHq2vXP/V6jSG25kkUsigYLp3rthMuzPrzZ8zygl54VWfPmnbXJ1K7dSv74XZ+7mLS38fW78N7j3GqISvn+tfem9/5L/v2uyxz7DSTSyudK6uvLZzO/tr488uvtm9vdHhpebqZxu16mGm5U7Ocqeed5jCpcfuB+f4O/9hO6+1eYNTvSbMWrlyoLZ/28VSv1ZySgIf99Je7Pec5N+eaHbu1qT//hl1XcP6VtpAIXiQ0a/F8TRamfb0h9x/Zu9tFlsdB+yGIc8Y7N9MYvHF+5tHDfq/HdrfZ84OdfzPaNC5C7vxesBRrMODMXCd4D4A05Q8ijUMcF87Z/pCFL6hR8EahPnI2sGZtp5Xkwe8NMkEIeawaQA0ijk4DxSU2L5Qi0ABVQ1X6/TySQoyDgy2UAkIC4CSIoVA4dL5wzge6YAIZxENBbwWRcqimx3q7NUmmijlQDQfsU1JEFVRjRFUV6kswVbggtCQGnwLlEAAJaKj4WDGDI0qVrBmhoRpIqSBZgob2ONofsrmSONADc1Q9gGfFowoeJVRgn+t6I3WSrKCopEx0xVhpT3bd8cGVAKha3YYG6BgfqzuZ8KgjfeWQg5awLKWq84/e1kmLfhHTx7hCJXPssezJ0518M8f+mZgQOlL3Zd3/f2jlJ2kHDmR8AAAAJXRFWHRkYXRlOmNyZWF0ZQAyMDE0LTAzLTI0VDIxOjQwOjM3KzAxOjAw+jamhAAAACV0RVh0ZGF0ZTptb2RpZnkAMjAxNC0wMy0yNFQyMTo0MDozNyswMTowMItrHjgAAAARdEVYdGpwZWc6Y29sb3JzcGFjZQAyLHVVnwAAACB0RVh0anBlZzpzYW1wbGluZy1mYWN0b3IAMngyLDF4MSwxeDFJ+qa0AAAAAElFTkSuQmCC"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/awy.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">Teh Cube</div>
    <div class="fm-cle-psm">
        Away
    </div>
</div><div id="tr=Y;id=tehcube;lgn=phedoreanu" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/yah.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/onl.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">tehcube</div>
    <div class="fm-cle-psm">
        Available
    </div>
</div><div id="tr=G;id=35tlmcw0n5g2x3oss0n0de4k60@public.talk.google.com;lgn=adrian.fedoreanu@gmail.com" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/ggl.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/awy.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">Tiberiu Corbu</div>
    <div class="fm-cle-psm">
        Away
    </div>
</div><div id="tr=K;id=tobyforman;lgn=phedoreanu" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/sky.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/onl.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">tobyforman</div>
    <div class="fm-cle-psm">
        Tool - 10,00 days rocks!
    </div>
</div><div id="tr=Y;id=tac_vlad2006;lgn=phedoreanu" class="fm-cle 
        " style="display: block;">
    <div style="background:url(&#39;https://plus.im/static/img/tr_icons/small/yah.png&#39;) center no-repeat;" class="fm-cle-tr">
    </div>

    <div class="fm-cle-ava"><img src="data:image/png;base64,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"></div>
    <div style="background:url(&#39;https://plus.im/static/img/st/new2/onl.png&#39;) center no-repeat;" class="fm-cle-st">
    </div>
    <div class="fm-cle-name">vlad</div>
    <div class="fm-cle-psm">
        Available
    </div>
</div></div>
        </div>
        <div id="fm_chats_wrapper" style="display: none;">
            <div id="fm_chats" style="height: 240px;">
            </div>
        </div>
        <div id="fm_news_wrapper" style="display: none;">
            <div id="fm_news" style="height: 240px;">
            </div>
        </div>
    </div>
<div id="fm_add_account" class="fm-base-content" style="height: 300px;">
    <div style="padding:10px; background-color:#F2F2F2; border-bottom: 1px solid #cfcfcf;">
        Service: 
        <img id="fm_add_acc_selimg" src="./WebServerST_files/msn.png">
        <select name="service">
            <option value="M">MSN / Live!</option>
            <option value="A">AIM</option>
            <option value="G">Google Talk</option>
            <option value="Y">Yahoo!</option>
            <option value="I">ICQ</option>
            <option value="J">Jabber</option>
            <!--option value="P">MySpace</option-->
            <option value="F">Facebook</option>
            <option value="K">Skype</option>
            <option value="8">Mamba</option>
            <option value="V">VKontakte</option>
            <option value="X">Yandex IM</option>
            <option value="R">Mail.ru Agent</option>
            <option value="O">Odnoklassniki.ru IM</option>
        </select>
    </div>
    <div style="padding: 10px 10px;">
        <div id="fm_add_acc_login">Login: </div>
        <input name="lgn">
        <div id="fm_add_acc_pass">Password: </div>
        <input name="pwd" type="password">
        <div>
            <input name="conn_on_start" id="fm_conn_on_start" type="checkbox" checked="checked"> 
            <label for="fm_conn_on_start">Connect on start</label>
            <span id="fm_add_acc_hddn" style="display:none"></span>
        </div>
        <div>
            <input name="store_history" id="fm_store_history" type="checkbox"> 
            <label for="fm_store_history">Store chat history</label>
        </div>
        <div class="fm-jabber-extended">
            <input name="jbr_host" id="fm_jbr_host" placeholder="server host (optional)">
            <input name="jbr_port" id="fm_jbr_port" placeholder="port" style="width: 40px">
            <div>
                <input name="jbr_use_ssl" id="fm_jbr_use_ssl" type="checkbox"> 
                <label for="fm_jbr_use_ssl">Use SSL encryption</label>
            </div>
        </div>
    </div>
    <div class="fm-addacc-commands" style="padding: 10px;">
        <a href="http://playground.arduino.cc/Code/WebServerST?action=sourceblock&num=1#" data-action="save" class="fm-btn primary">Save</a> 
        <a href="http://playground.arduino.cc/Code/WebServerST?action=sourceblock&num=1#" data-action="cancel" class="fm-btn">Cancel</a>
    </div>
</div><div id="fm_add_contact" class="fm-base-content" style="height: 300px;">
    <div style="padding:10px; background-color:#F2F2F2; border-bottom: 1px solid #cfcfcf;">
        Account: <select name="account"><option value="Y:phedoreanu">phedoreanu(Yahoo! IM)</option><option value="G:adrian.fedoreanu@gmail.com">adrian.fedoreanu@gmail.com(Google Talk)</option><option value="K:phedoreanu">phedoreanu(Skype)</option></select>
    </div>
    <div style="padding: 10px;">
        <div>Contact ID:</div> 
        <input name="cid" size="20" autocomplete="off">
        <div>Nickname:</div>
        <input name="nick" size="20" autocomplete="off">
    </div>
    <div style="padding: 0 10px;">
        <a href="http://playground.arduino.cc/Code/WebServerST?action=sourceblock&num=1#" data-action="add" class="fm-btn primary">Add Contact</a>
        <a href="http://playground.arduino.cc/Code/WebServerST?action=sourceblock&num=1#" data-action="cancel" class="fm-btn">Cancel</a>
    </div>
</div><div id="fm_accounts" class="fm-base-content" style="height: 300px;">
    <ul id="fm_accs_settings_tabs" class="fm-tabs-holder">
        <li id="fm_astabs_accounts_tab">Accounts</li>
        <li id="fm_astabs_settings_tab">Settings</li>
        <div class="fm-clr"></div>
    </ul>

    <div id="fm_settings_wrapper">
        <div style="padding-bottom: 10px;">
            <label>
                <input id="fm_settings_hideoffline" type="checkbox"> 
                Hide offline contacts
            </label>
        </div>
        <div style="padding-bottom: 10px;">
            <label>
                <input id="fm_settings_mutesounds" type="checkbox">
                Mute sounds
            </label>
        </div>
        <div style="padding-bottom: 10px;">                <label>                    <input id="fm_settings_disablenotify" type="checkbox">                    Disable browser notifications                </label>            </div>
        <div style="padding-bottom: 10px;">
            <label>
                <input id="fm_settings_showgroups" type="checkbox">
                Show groups
            </label>
        </div>
        <div>
            <label>
                Language: 
                <select id="fm_settings_language"> 
                    <option value="en">English</option>
                    <option value="ru">&#1056;&#1091;&#1089;&#1089;&#1082;&#1080;&#1081;</option>
                    <option value="es">Espanol</option>
                </select>
            </label>
        </div>
    </div>

    <div id="fm_accounts_wrapper">
        <div id="fm_account_list"><div id="Y:phedoreanu" class="fm-account fm-tr-Y">
    <div class="fm-rem-acc-btn" title="Delete"></div>
    <div class="fm-edit-acc-btn" title="Edit"></div>

    <label for="fm_account_onoff_Y:phedoreanu">
        <div class="fm-tr-icon" style="background:url(&#39;https://plus.im/static/img/tr_icons/small/yah.png&#39;) 2px center no-repeat;">
        </div>
        <input id="fm_account_onoff_Y:phedoreanu" type="checkbox" checked="checked">
        <span class="fm-account-display-name">phedoreanu</span>
    </label>
    <div class="fm-clr"></div>
</div><div id="G:adrian.fedoreanu@gmail.com" class="fm-account fm-tr-G">
    <div class="fm-rem-acc-btn" title="Delete"></div>
    <div class="fm-edit-acc-btn" title="Edit"></div>

    <label for="fm_account_onoff_G:adrian.fedoreanu@gmail.com">
        <div class="fm-tr-icon" style="background:url(&#39;https://plus.im/static/img/tr_icons/small/ggl.png&#39;) 2px center no-repeat;">
        </div>
        <input id="fm_account_onoff_G:adrian.fedoreanu@gmail.com" type="checkbox" checked="checked">
        <span class="fm-account-display-name">adrian.fedoreanu@gmail.com</span>
    </label>
    <div class="fm-clr"></div>
</div><div id="K:phedoreanu" class="fm-account fm-tr-K">
    <div class="fm-rem-acc-btn" title="Delete"></div>
    <div class="fm-edit-acc-btn" title="Edit"></div>

    <label for="fm_account_onoff_K:phedoreanu">
        <div class="fm-tr-icon" style="background:url(&#39;https://plus.im/static/img/tr_icons/small/sky.png&#39;) 2px center no-repeat;">
        </div>
        <input id="fm_account_onoff_K:phedoreanu" type="checkbox" checked="checked">
        <span class="fm-account-display-name">phedoreanu</span>
    </label>
    <div class="fm-clr"></div>
</div></div>
        <div class="fm-accs-commands">
            <a href="http://playground.arduino.cc/Code/WebServerST?action=sourceblock&num=1#" data-action="add" class="fm-btn primary fm-big-add-acc-btn">
                Add Account
            </a>
        </div>
    </div>
    <div id="fm_feedback_wrapper">
        <a class="feedback_button" href="http://playground.arduino.cc/Code/WebServerST?action=sourceblock&num=1#"> Feedback 
    </a></div><a class="feedback_button" href="http://playground.arduino.cc/Code/WebServerST?action=sourceblock&num=1#">
</a></div></div><form id="fm_upload_form" method="post" enctype="multipart/form-data" action="" target="iframe-post-form">
    <input type="file" name="fm_file_upload" id="fm_file_upload">
    <input type="hidden" id="fm_instid" name="instid" value="41517D564777_673726B52149">
    <input type="hidden" id="fm_partner" name="partner" value="shape">
    <input type="submit" value="Upload">
</form><div id="fm_microbase" class="" style="display: block;">
    
</div><div id="fm_smiley_panel">
    
    <div class="fm-smile-clickable" data-value=" :) ">
        <img src="./WebServerST_files/smiley-smile.png" title="Smile">
    </div>
    <div class="fm-smile-clickable" data-value=" ;) ">
        <img src="./WebServerST_files/smiley-wink.png" title="Wink">
    </div>
    <div class="fm-smile-clickable" data-value=" :( ">
        <img src="./WebServerST_files/smiley-sad.png" title="Sad / Upset">
    </div>
    <div class="fm-smile-clickable" data-value=" :D ">
        <img src="./WebServerST_files/smiley-lol.png" title="Laugh Out Loud">
    </div>
    <div class="fm-smile-clickable" data-value=" 8) ">
        <img src="./WebServerST_files/smiley-cool.png" title="Cool">
    </div>
    <div class="fm-smile-clickable" data-value=" :0 ">
        <img src="./WebServerST_files/smiley-eek.png" title="Shocked">
    </div>
    <div class="fm-smile-clickable" data-value=" :) ">
        <img src="./WebServerST_files/smiley-cry.png" title="Crying">
    </div>
    <div class="fm-smile-clickable" data-value=" :* ">
        <img src="./WebServerST_files/smiley-kiss.png" title="Kiss">
    </div>
    <div class="fm-smile-clickable" data-value=" :S ">
        <img src="./WebServerST_files/smiley-confuse.png" title="Confused">
    </div>
    <div class="fm-smile-clickable" data-value=" &gt;:-) ">
        <img src="./WebServerST_files/smiley-evil.png" title="Evil">
    </div>
    <div class="fm-smile-clickable" data-value=" :@ ">
        <img src="./WebServerST_files/smiley-mad.png" title="Angry / Mad">
    </div>
    <div class="fm-smile-clickable" data-value=" :P ">
        <img src="./WebServerST_files/smiley-razz.png" title="Sticking Out Tongue">
    </div>
    <div class="fm-smile-clickable" data-value=" |) ">
        <img src="./WebServerST_files/smiley-sleep.png" title="Sleeping">
    </div>
    <div class="fm-smile-clickable" data-value=" :X ">
        <img src="./WebServerST_files/smiley-zipper.png" title="Lips are Sealed">
    </div>

</div><iframe id="iframe-post-form" name="iframe-post-form" style="display:none"></iframe></body></html>