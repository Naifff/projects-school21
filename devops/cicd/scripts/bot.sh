#!/bin/bash
TELEGRAM_BOT_TOKEN="6587010038:AAHavPrqgGv1lo3gPlOaYMoqv0JlNYHYqoc"
TELEGRAM_USER_ID="800151816"
TIME='10 seconds'
URL="https://api.telegram.org/bot$TELEGRAM_BOT_TOKEN/sendMessage"
if [[ $1 = "success" ]]; then
    STATUS=✅
else
    STATUS=❌
fi
TEXT="Stage '$2'%0AStatus: $STATUS%0A%0AProject:+$CI_PROJECT_NAME%0AURL:+$CI_PROJECT_URL/pipelines/$CI_PIPELINE_ID/%0ABranch:+$CI_COMMIT_REF_SLUG"

curl -s --max-time $TIME -d "chat_id=$TELEGRAM_USER_ID&disable_web_page_preview=1&text=$TEXT" $URL > /dev/null