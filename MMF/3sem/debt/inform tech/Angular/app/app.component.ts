import { Component, OnInit } from '@angular/core';
import { Item } from "./resources/add-class/Item";
import { ItemService } from "./resources/add-class/ItemService";


@Component({
    selector: 'my-app',
    styleUrls: ['./app/resources/style/style.css'],
    template: `
        <div class="content"></div>

        <ul>
            <li *ngFor="let item of items">
                <!--<a [attr.href]="'#'+item.id">-->
                <a [routerLink]="[item.id]">
                    <div class="left-menu my-shadow">
                        <div class="innertext">
                            {{ item?.name }}
                        </div>
                    </div>
                </a>
            </li>
        </ul>

        <router-outlet></router-outlet>
    `
})
export class AppComponent implements OnInit {
    items: Item[];

    constructor(private _itemService: ItemService) {
    }

    ngOnInit() {
        this._itemService.getItems().subscribe((data: Response) => this.items = data.json());
    }
}
