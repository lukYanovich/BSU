import { NgModule } from '@angular/core';
import { AppComponent } from './app.component';
import { BrowserModule } from '@angular/platform-browser';
import { HttpModule } from "@angular/http";
import { FormsModule } from "@angular/forms";
import { RouterModule } from "@angular/router";
import { One } from "./resources/add-components/one";
import { ItemService } from "./resources/add-class/ItemService";
import { Two } from "./resources/add-components/two";
import { Three } from "./resources/add-components/three";


@NgModule({
    imports: [
        BrowserModule,
        HttpModule,
        FormsModule,
        RouterModule.forRoot([
            {
                path: "1",
                component: One
            },
            {
                path: "2",
                component: Two
            },
            {
                path: "3",
                component: Three
            }
        ])
    ],
    declarations: [ AppComponent, One, Two, Three ],
    bootstrap: [ AppComponent ],
    providers: [ ItemService ]
})
export class MyAppAppModule {}
