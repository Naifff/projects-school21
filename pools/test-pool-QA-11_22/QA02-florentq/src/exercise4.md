# Блок Authorization


## Test-case 1. Проверка эндпоинта POST /authorization​/login

Precondition: Авторизация не пройдена. Открыть страницу  http://94.139.255.171:4200/swagger/index.html 
| STEPS | EXPECTATION |
| ------ | ------ |
| 1. Открыть описание эндпоинта POST ​/api​/authorization​/login и нажми на кнопку Try it out;| |
| 2. В теле запроса укажи почту и пароль для входа в аккаунт. Например, чтобы войти в аккаунт администратора, нужно вписать: | {
  "email": "admin@mail.ru",
  "password": "Admin"
}|
| 3.Выполни запрос кнопкой Execute; | В случае успешной авторизаци, в ответе от сервера поступит access token, который нужно скопировать |
| 4.Вверху страницы, в правой части нажми на кнопку Authorize; | |
| 5.В открывшемся текстовом поле впиши bearer "token", вместо "token" вставить тот, что был скопировал ранее( без кавычек); | После этого ты сможешь выполнять запросы, которые требуют прохождение авторизации. |



## Test-case 2. Проверка эндпоинта POST /authorization​/register

Precondition: Авторизация пройдена. Открыть страницу  http://94.139.255.171:4200/swagger/index.html 
| STEPS | EXPECTATION |
| ------ | ------ |
| 1. Открыть описание эндпоинта POST ​/api​/authorization​/register и нажми на кнопку Try it out;| |
| 2. В поле "Request body" ввести валидные значения после двоеточия. Поле roleId нужно сменить на id роли клиента | _Пример:_ {<br>"name": "string",<br>"birthday": "2023-01-31T18:09:16.535Z",<br>"sex": 0,<br>"email":<br>"user@example.com",<br>"password": "string",<br>"roleId":<br>"3fa85f64-5717-4562-b3fc-2c963f66afa6",<br>"bankId": "3fa85f64-5717-4562-b3fc-2c963f66afa6"} |
| 3.Выполни запрос кнопкой Execute. | В случае успешной авторизаци, в ответе от сервера поступит код ответа *201 Success* {<br>"userId":<br>"3fa85f64-5717-4562-b3fc-2c963f66afa6",<br>"name": "string",<br>"birthaday": "2023-01-31T18:17:53.764Z",<br>"sex": 0,<br>"email": "string",<br>"roleId": "3fa85f64-5717-4562-b3fc-2c963f66afa6",<br>"bankId": "3fa85f64-5717-4562-b3fc-2c963f66afa6",<br>"state": 0} |


## Test-case 3. Проверка эндпоинта POST /authorization​/refresh-token

Precondition: Авторизация пройдена. Открыть страницу  http://94.139.255.171:4200/swagger/index.html 
| STEPS | EXPECTATION |
| ------ | ------ |
| 1. Открыть описание эндпоинта POST ​/api​/authorization​/refresh-token и нажми на кнопку Try it out;| |
| 2. В поле "Request body" ввести валидные значения, ранее полученный токен | Например: eyJhbGciOiJodHRwOi8vd3d3LnczLm9yZy8yMDAxLzA0L3htbGRzaWctbW9yZSNobWFjLXNoYTUxMiIsInR5cCI6IkpXVCJ9.eyJ1c2VySWQiOiI3Y2JiNWZiOS0zYmQzLTQ1MmYtOTc5NS02NmM3NDU4YmIzNTMiLCJodHRwOi8vc2NoZW1hcy54bWxzb2FwLm9yZy93cy8yMDA1LzA1L2lkZW50aXR5L2NsYWltcy9uYW1lIjoiQWRtaW4iLCJodHRwOi8vc2NoZW1hcy54bWxzb2FwLm9yZy93cy8yMDA1LzA1L2lkZW50aXR5L2NsYWltcy9lbWFpbGFkZHJlc3MiOiJhZG1pbkBtYWlsLnJ1IiwiaHR0cDovL3NjaGVtYXMubWljcm9zb2Z0LmNvbS93cy8yMDA4LzA2L2lkZW50aXR5L2NsYWltcy9yb2xlIjoiQWRtaW4iLCJleHAiOjE2NzUxOTQyNTZ9.bAkwpyDF2APRJx6ML4zcOv3CTHgiaqu8KV7xNlMLqseTBJ2fhHYdv4pP5wf_x162JN7XIuExAzL-zCWQxkznkQ |
| 3.Выполни запрос кнопкой Execute. | В случае успешной авторизаци, в ответе от сервера поступит код ответа *200 Success* |



## Test-case 4. Проверка эндпоинта POST /api/banks

Precondition: Авторизация пройдена. Открыть страницу  http://94.139.255.171:4200/swagger/index.html 
| STEPS | EXPECTATION |
| ------ | ------ |
| 1. Открыть описание эндпоинта POST /api​/banks  и нажми на кнопку Try it out;| |
| 2. Заполнить все необходимы поля. | _Пример:_ {<br>"name": "A-Bank",<br>"description": "Описание банка",<br>"shortName": "A"
}|
| 3.Выполни запрос кнопкой Execute. | После выполнения запроса получим результат. Например: {<br>"bankId": "697f2876-c9b2-4656-a5a9-8e5bcfaec354",<br>"name":<br>"A-Bank",<br>"description": "Описание банка",<br>"state": 2,<br>"rating": 0,<br>"shortName": "A"}|



## Test-case 5. Проверка эндпоинта GET /api/banks

Precondition: Авторизация пройдена. Открыть страницу  http://94.139.255.171:4200/swagger/index.html 
| STEPS | EXPECTATION |
| ------ | ------ |
| 1. Открыть описание эндпоинта GET /api/banks  и нажми на кнопку Try it out;| |
| 2. Выполни запрос кнопкой Execute. | После выполнения запроса получим результат с кодом ответа 200 и списком банков. |



## Test-case 6. Проверка эндпоинта PATCH /api/banks/id

Precondition: Авторизация пройдена. Открыть страницу  http://94.139.255.171:4200/swagger/index.html 
| STEPS | EXPECTATION |
| ------ | ------ |
| 1. Открыть описание эндпоинта PATCH /api/banks/id  и нажми на кнопку Try it out;| |
| 2. В поле Bank id внести валидное значение. _Например:_b57ce0d9-1594-4c20-aa4d-8e5e62b47dc1 .| Значение внесено в поле. |
| 3. Выполни запрос кнопкой Execute.| После выполнения запроса получим результат с кодом ответа 200. _Пример ответа:_ {<br>"bankId":<br>"b57ce0d9-1594-4c20-aa4d-8e5e62b47dc1",<br>"name": "Сбербанк",<br>"description": "Отличный интернет-банк.",<br>"state": 2,<br>"rating": 0,<br>"shortName": "Sber"}|



## Test-case 7. Проверка эндпоинта DELETE /api/banks/id

Precondition: Авторизация пройдена. Открыть страницу  http://94.139.255.171:4200/swagger/index.html 
| STEPS | EXPECTATION |
| ------ | ------ |
| 1. Открыть описание эндпоинта DELETE /api/banks/id и нажми на кнопку Try it out;| |
| 2. В поле Bank id внести валидное значение. _Например:_6d1dec6d-ce7c-4c4d-bd43-c84cf9498249| Значение внесено в поле. |
| 3. Выполни запрос кнопкой Execute. | После выполнения запроса получим результат с кодом ответа 204. _Пример ответа:_  date: Tue,31 Jan 2023 16:17:25 GMT server: Kestrel |



## Test-case 8. Проверка эндпоинта GET /api/banks/id

Precondition: Авторизация пройдена. Открыть страницу  http://94.139.255.171:4200/swagger/index.html 
| STEPS | EXPECTATION |
| ------ | ------ |
| 1. Открыть описание эндпоинта GET /api/banks/id  и нажми на кнопку Try it out| |
| 2. В поле Bank id внести валидное значение _Например:_b57ce0d9-1594-4c20-aa4d-8e5e62b47dc1 | Значение внесено в поле. |
| 3. Выполни запрос кнопкой Execute. | После выполнения запроса получим результат с кодом ответа 200. _Пример ответа:_ {<br>"bankId":<br>"b57ce0d9-1594-4c20-aa4d-8e5e62b47dc1",<br>"name": "Сбербанк",<br>"description": "Отличный интернет-банк.",<br>"state": 2,<br>"rating": 0,<br>"shortName": "Sber"}|


## Test-case 9. Проверка эндпоинта GET /api/banks/Name

Precondition: Авторизация пройдена. Открыть страницу  http://94.139.255.171:4200/swagger/index.html 
| STEPS | EXPECTATION |
| ------ | ------ |
| 1. Открыть описание эндпоинта GET /api/banks/Name  и нажми на кнопку Try it out;| |
| 2. В поле Name внести валидное значение. _Например:_Сбербанк | Значение внесено в поле. |
| 3. Выполни запрос кнопкой Execute. | После выполнения запроса получим результат с кодом ответа 200. _Пример ответа:_<br>{"bankId":<br>"69613d84-8d38-499c-bab7-e2e9af928d77",<br>"name": "Сбербанк",<br>"description": "Отличный интернет-банк.",<br>"state": 2,<br>"rating": 0,<br>"shortName": "Sber"},<br>{<br>"bankId":<br>"b57ce0d9-1594-4c20-aa4d-8e5e62b47dc1",<br>"name": "Сбербанк",<br>"description": "Отличный интернет-банк.",<br>"state": 2,<br>"rating": 0,<br>"shortName": "Sber"}|



## Test-case 10. Проверка эндпоинта GET /api/banks/id/feedbacks

Precondition: Авторизация пройдена. Открыть страницу  http://94.139.255.171:4200/swagger/index.html 
| STEPS | EXPECTATION |
| ------ | ------ |
| 1. Открыть описание эндпоинта GET /api/banks/id/feedbacks  и нажми на кнопку Try it out;| |
| 2. В поле Bank id внести валидное значение. _Например:_1406aa87-00bc-4ed5-a128-8e61242de10e | Значение внесено в поле. |
| 3. Выполни запрос кнопкой Execute. | После выполнения запроса получим результат с кодом ответа 200. _Пример ответа:_ {<br>"feedbackId":<br>"872cce22-1778-4764-b811-54baf663ee23",<br>"rating": 5,<br>"text": "Good ipoteka, rekomenduyu",<br>"date": "2023-01-16T07:00:50.324765Z",<br>"state": 2,<br>"isLatest": true,<br>"pruductId": "292c9f09-cb44-483f-b4c7-0176bacc4289",<br>"userId": "c1e8ff80-1b73-48fa-87e1-79590185abc6"}|



## Test-case 11. Проверка эндпоинта GET /api/banks/id/employee

Precondition: Авторизация  пройдена в качестве сотрудника банка. Открыть страницу  http://94.139.255.171:4200/swagger/index.html 
| STEPS | EXPECTATION |
| ------ | ------ |
| 1. Открыть описание эндпоинта GET /api/banks/id/employee  и нажми на кнопку Try it out;| |
| 2.В поле Bank id внести валидное значение. _Например:_1b2f3bcd-e2c9-462b-bae9-b548fded413f . В селекторе фильтра onApproval выбрать значение "true"." | Значение внесено в поле. |
| 3. Выполни запрос кнопкой Execute. | После выполнения запроса получим результат с кодом ответа 200. _Пример ответа:_ {<br>"userId": "2451d9aa-fe7a-4023-976b-18552e4c5289",<br>"name": "user14@bank.ru",<br>"birthaday": "2000-08-31T20:00:00Z",<br>"sex": 1,<br>"email": "user14@bank.ru",<br>"roleId": "915c53dc-a10d-4755-ada0-4dfe6eca69c2",<br>"bankId": "48dd1139-c2c0-47cf-98c1-c143b0a48c25",<br>"state": 1 }|
  
  
## Test-case 12. Проверка эндпоинта GET /api/banks/id/products

Precondition: Авторизация пройдена. Открыть страницу  http://94.139.255.171:4200/swagger/index.html 
| STEPS | EXPECTATION |
| ------ | ------ |
| 1. Открыть описание эндпоинта POST /api​/banks  и нажми на кнопку Try it out;| |
| 2.В поле Bank id внести валидное значение. 
_Например:_ 1406aa87-00bc-4ed5-a128-8e61242de10e | Значение внесено в поле. |
| 3. Выполни запрос кнопкой Execute. | После выполнения запроса получим результат с кодом ответа 200. _Пример ответа:_ {<br>"productId": "292c9f09-cb44-483f-b4c7-0176bacc4289",<br>"name": "Ipoteka",<br>"description": "ipoteka na veka",<br>"state": 2,<br>"avgRating": 4.3333335,<br>"bankId": "1406aa87-00bc-4ed5-a128-8e61242de10e",<br>"categoryId": "f2d71dda-de6a-4c61-b9c6-e634adf1a9f4"}|


## Test-case 13. Проверка эндпоинта POST /api/banks со старым токеном (после refresh-token).

Precondition: Авторизация пройдена под старым токеном. Открыть страницу  http://94.139.255.171:4200/swagger/index.html 
| STEPS | EXPECTATION |
| ------ | ------ |
| 1. Открыть описание эндпоинта POST /api​/banks  и нажми на кнопку Try it out;| |
| 2. Заполнить все необходимы поля. | _Пример:_ {<br>"name": "A-Bank",<br>"description": "Описание банка",<br>"shortName": "A"
}|
| 3.Выполни запрос кнопкой Execute. | После выполнения запроса получим код ответа 403, Error: Forbidden. |

`Resolution: Fail. Bank created with Authorization after refresh-token`
