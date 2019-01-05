import {Component, OnInit} from "@angular/core";
import {ItemService} from "../add-class/ItemService";
import {ItemAbout} from "../add-class/ItemAbout";


@Component({
    selector: "my-one",
    styleUrls: ['./app/resources/style/style.css'],
    template: `
        <div *ngIf="item_about" class="right-menu"> {{ item_about?.data }}</div>
    `
})
export class One implements OnInit {
    item_about: ItemAbout;

    constructor(private _itemService: ItemService) {
    }

    ngOnInit() {
        this._itemService.getAbout(1).subscribe((data: Response) => this.item_about = data.json());
    }
}